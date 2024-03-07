/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:18:22 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/07 19:05:02 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "color.h"

static unsigned int	phong_light(t_light *l, double dot, t_ray *lray)
{
	t_vec			reflex;
	double			s_fact;

	lray->zero = unit_vector(&lray->hit.p);
	reflex = mult_new(&lray->hit.norm, 2 * dot);
	reflex = substr_vec(&reflex, &lray->norm);
	reflex = unit_vector(&reflex);
	s_fact = dot_prod(&reflex, &lray->zero);
	if (s_fact >= 0)
		return (0);
	s_fact = pow(s_fact, 500);
	if (s_fact < 0)
		s_fact = -s_fact;
	return (color_x_fact(rgb_to_hex(l->rgb), s_fact * l->b));
}

static unsigned int	diffuse_light(t_light *light, t_hit *hit, double d_fact)
{
	unsigned int	d_color;

	if (d_fact < 0)
		d_fact = 0;
	d_color = color_x_fact(rgb_to_hex(light->rgb), light->b * d_fact);
	return (color_mult(rgb_to_hex(hit->rgb), d_color));
}

static void	obj_color(t_light *l, t_ray *lray, unsigned int *color, double dot)
{
	unsigned int	diffuse;

	diffuse = diffuse_light(l, &lray->hit, dot);
	*color = add_color(diffuse, *color);
	if (dot > 0)
		*color = add_color(*color, phong_light(l, dot, lray));
}

static void	get_shadows(t_ray *lray, t_hit *hit, t_item *obj, double dot)
{
	double	d;
	t_item	*tmp;

	d = dist(&lray->zero, &lray->orig);
	tmp = obj;
	if (dot < 0)
		return ;
	while (tmp)
	{
		if (tmp != hit->obj)
		{
			tmp->intersect(&tmp->type, lray, tmp);
			if (lray->dist < d)
			{
				hit->obst = true;
				break ;
			}
		}
		tmp = tmp->next;
	}
}

void	get_color(t_sc *sc, t_item *obj, t_hit *hit)
{
	t_ray	lray;
	t_light	*light;
	double	dot;

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
		dot = dot_prod(&hit->norm, &lray.norm);
		get_shadows(&lray, hit, obj, dot);
		lray.hit = *hit;
		if (!hit->obst)
			obj_color(light, &lray, &sc->mlx.color, dot);
		light = light->next;
	}
}
