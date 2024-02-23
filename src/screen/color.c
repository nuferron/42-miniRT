/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:18:22 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/23 20:13:42 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
}
