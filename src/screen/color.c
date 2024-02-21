/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:18:22 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/20 21:50:31 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*unsigned int	rgb_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}*/

unsigned int	rgb_to_hex(int *rgb)
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	color_intensity(int *rgb, float intensity)
{
	rgb[0] *= intensity;
	rgb[1] *= intensity;
	rgb[2] *= intensity;
}

void	rerange_rgb(int *color)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (color[i] > 255)
			color[i] = 255;
		else if (color[i] < 0)
			color[i] = 0;
		i++;
	}
}

void	add_color(int *color, int *add)
{
	color[0] += add[0];
	color[1] += add[1];
	color[2] += add[2];
	rerange_rgb(color);
}

void	multiply_color(int *color, int *mult)
{
	color[0] = color[0] * mult[0] / 255;
	color[1] = color[1] * mult[1] / 255;
	color[2] = color[2] * mult[2] / 255;
	rerange_rgb(color);
}
