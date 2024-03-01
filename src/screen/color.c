/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:18:22 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/29 23:16:42 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
	s_fact = pow(s_fact, 1000);
	if (s_fact < 0)
		s_fact = 0;
	specular = color_x_fact(rgb_to_hex(light->rgb), s_fact);
	return (specular);
}

unsigned int	diffuse_light(t_light *light, t_hit *hit, 
		unsigned int amb, float d_fact)
{
	unsigned int	d_color;

	if (d_fact > 0)
		d_color = color_x_fact(rgb_to_hex(light->rgb), light->b * d_fact);
	else
		d_color = 0;
	return (color_mult(rgb_to_hex(hit->rgb), add_color(amb, d_color)));
}

/*void	obj_color(t_amb *amb, t_light *light, unsigned int *color, t_hit *hit)
{
	unsigned int	ambient;
	unsigned int	diffuse;
	float			dot;
	t_vec			l_ray;

	while (light)
	{
		l_ray = substr_vec(&light->pos, &hit->p);
		l_ray = unit_vector(&l_ray);
		dot = dot_prod(&l_ray, &hit->norm);
		if ((hit->type == pla || hit->type == disk) && dot < 0)
		{
			opp_vec(&hit->norm);
			dot = -dot;
		}
		ambient = color_x_fact(color_mult(rgb_to_hex(light->rgb),
					rgb_to_hex(hit->rgb)), amb->ratio);
		diffuse = diffuse_light(light, hit, color_x_fact(rgb_to_hex(amb->rgb),
					amb->ratio), dot);
		*color = add_color(color_mean(ambient, diffuse), *color);
		if (dot_prod(&l_ray, &hit->norm) > 0.2)
			*color = add_color(*color, phong_light(light, hit, dot, &l_ray));
		light = light->next;
	}
}*/

void	obj_color(t_amb *amb, t_light *light, unsigned int *color, t_hit *hit)
{
	unsigned int	ambient;
	unsigned int	diffuse;
	float			dot;
	t_vec			l_ray;

	l_ray = substr_vec(&light->pos, &hit->p);
	l_ray = unit_vector(&l_ray);
	dot = dot_prod(&hit->norm, &l_ray);
	if (hit->type == pla && dot < 0)
	{
		opp_vec(&hit->norm);
		dot = -dot;
	}
	ambient = color_x_fact(color_mult(rgb_to_hex(light->rgb),
				rgb_to_hex(hit->rgb)), amb->ratio);
	if (hit->obst)
	{
		*color = add_color(*color, ambient);
		return ;
	}
	diffuse = diffuse_light(light, hit, color_x_fact(rgb_to_hex(amb->rgb),
				amb->ratio), dot);
	*color = add_color(color_mean(ambient, diffuse), *color);
	if (dot_prod(&l_ray, &hit->norm) > 0.1)
		*color = add_color(*color, phong_light(light, hit, dot, &l_ray));
}

unsigned int	get_color(t_amb *amb, t_light *light, t_item *obj, t_hit *hit)
{
	t_ray	ray;
	t_item	*tmp;
	double	d;
	unsigned int	color;

	color = 0;
	while (light)
	{
		hit->obst = false;
		init_light_ray(&ray, light, hit);
		d = dist(&ray.zero, &ray.orig);
		tmp = obj;
		while (tmp)
		{
			if (tmp != hit->obj) 
			{
				tmp->intersect(&tmp->type, &ray, tmp);
				if (ray.dist < d && ray.hit.obst == true)
				{
					hit->obst = true;
					break ;
				}
			}
			tmp = tmp->next;
		}
		obj_color(amb, light, &color, hit);
		light = light->next;
	}
	return (color);
}
