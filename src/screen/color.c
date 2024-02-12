/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:18:22 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/12 13:43:25 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	rgb_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	obj_color(t_sc *sc, int *color, t_vec *light, t_vec *norm)
{
	double	dot;

	dot = dot_prod(light, norm);
	if (dot <= 0)
		*color = 0x000000;
	else
		*color = *color + sc->light.b * dot + sc->amb.ratio;
}
