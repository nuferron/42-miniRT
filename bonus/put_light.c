/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:23:31 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/23 20:48:59 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static unsigned int	phong_light(t_light *light, t_hit *hit, float dot)
{
	t_vec			reflex;
	float			s_fact;
	unsigned int	specular;
	t_vec			cam_hit;

	reflex = mult_new(&hit->norm, 2 * dot);
	reflex = substr_vec(&reflex, &light->pos);
	unit_vector(&reflex, &reflex);
	unit_vector(&hit->p, &cam_hit);
	s_fact = pow(dot_prod(&reflex, &cam_hit), 500);
	specular = color_x_fact(rgb_to_hex(light->rgb), s_fact);
	return (specular);
}

/*
void	obj_color(t_amb *amb, t_light light, unsigned int *color, t_hit *hit)
{
	unsigned int	ambient;
	unsigned int	diffuse;
	float			dot;

	light.pos = substr_vec(&light.pos, &hit->p);
	unit_vector(&light.pos, &light.pos);
	dot = dot_prod(&light.pos, &hit->norm);
	if (hit->type == pla && dot < 0)
	{
		hit->norm = opp_vec(&hit->norm);
		dot = -dot;
	}
	ambient = color_x_fact(color_mult(rgb_to_hex(light.rgb),
			rgb_to_hex(hit->rgb)), amb->ratio);
	diffuse = diffuse_light(&light, hit,
			color_x_fact(rgb_to_hex(amb->rgb), amb->ratio), dot);
	*color = color_mean(diffuse, ambient);
	//if (dot_prod(&light.pos, &hit->norm) > 0.2)
	//	*color = add_color(*color, phong_light(&light, hit, dot));
}*/

void	obj_color(t_amb	*amb, t_light *light, unsigned int *color, t_hit *hit)
{
	unsigned int	ambient;
	unsigned int	diffuse;
	float			dot;
	t_vec			tmp;
	int				first;

	first = 0;
	while (light)
	{
		tmp = substr_vec(&light.pos, &hit->p);
		unit_vector(&tmp, &tmp);
		dot = dot_prod(&tmp, &hit->norm);
		if (hit->type == pla && dot < 0)
		{
			hit->norm = opp_vec(&hit->norm);
			dot = -dot;
		}
		ambient = color_x_fact(color_mult(rgb_to_hex(light.rgb),
				rgb_to_hex(hit->rgb)), amb->ratio);
		diffuse = diffuse_light(&light, hit,
				color_x_fact(rgb_to_hex(amb->rgb), amb->ratio), dot);
		if (first)
			*color = color_mean(diffuse, ambient);
		else
			*color = color_mean(diffuse, *color);
		if (dot_prod(&light.pos, &hit->norm) > 0.2)
			*color = add_color(*color, phong_light(&light, hit, dot));
	}
}
