/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:18:22 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/04 13:50:30 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "color.h"

static unsigned int	phong_light(t_light *light, t_hit *hit, float dot,
		t_vec *lray)
{
	t_vec			reflex;
	float			s_fact;
	unsigned int	specular;
	t_vec			cam_hit;

	cam_hit = unit_vector(&hit->p);
	reflex = mult_new(&hit->norm, 2 * dot);
	reflex = substr_vec(&reflex, lray);
	reflex = unit_vector(&reflex);
	s_fact = dot_prod(&reflex, &cam_hit);
	if (s_fact >= 0)
		return (0);
	s_fact = pow(s_fact, 400);
	if (s_fact < 0)
		s_fact = 0;
	specular = color_x_fact(rgb_to_hex(light->rgb), s_fact * light->b);
	return (specular);
}

static unsigned int	diffuse_light(t_light *light, t_hit *hit, float d_fact)
{
	unsigned int	d_color;

	if (d_fact < 0)
		d_fact = 0;
	d_color = color_x_fact(rgb_to_hex(light->rgb), light->b * d_fact);
	return (color_mult(rgb_to_hex(hit->rgb), d_color));
}

static void	obj_color(t_light *light, t_hit *hit, unsigned int *color)
{
	unsigned int	diffuse;
	float			dot;
	t_vec			lray;

	lray = substr_vec(&light->pos, &hit->p);
	lray = unit_vector(&lray);
	dot = dot_prod(&hit->norm, &lray);
	diffuse = diffuse_light(light, hit, dot);
	*color = add_color(diffuse, *color);
	if (dot_prod(&lray, &hit->norm) > 0)
		*color = add_color(*color, phong_light(light, hit, dot, &lray));
}

static void	get_shadows(t_ray *lray, t_hit *hit, t_item *obj, double dot)
{
	double	d;
	t_item	*tmp;

	d = dist(&lray->zero, &lray->orig);
	tmp = obj;
	while (tmp)
	{
		if (tmp != hit->obj)
		{
			if (dot < 0)
			{
				hit->obst = true;
				break ;
			}
			tmp->intersect(&tmp->type, lray, tmp);
			if (lray->dist < d)
			{
				//printf("d %f\tray.dist %f\n", d, ray.dist);
				hit->obst = true;
				break ;
			}
		}
		tmp = tmp->next;
	}
}

unsigned int	get_color(t_sc *sc, t_item *obj, t_hit *hit)
{
	t_ray	lray;
	t_light	*light;

	light = sc->light;
	sc->mlx.color = color_mult(color_x_fact(rgb_to_hex(sc->amb.rgb),
				sc->amb.ratio), rgb_to_hex(hit->rgb));
	while (light)
	{
		if (!light->b)
		{
			light = light->next;
			continue ;
		}
		hit->obst = false;
		init_light_ray(&lray, light, hit);
		get_shadows(&lray, hit, obj, dot_prod(&hit->norm, &lray.norm));
		if (!hit->obst)
			obj_color(light, hit, &sc->mlx.color);
		light = light->next;
	}
	return (sc->mlx.color);
}
