/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:57:16 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/27 18:59:49 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

unsigned int	rgb_to_hex(int *rgb)
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

unsigned int	color_x_fact(unsigned int hex, float n)
{
	int	r;
	int	g;
	int	b;

	r = ((hex >> 16) & 0xff) * n;
	g = ((hex >> 8) & 0xff) * n;
	b = (hex & 0xff) * n;
	return (r << 16 | g << 8 | b);
}

unsigned int	add_color(unsigned int c1, unsigned int c2)
{
	int	r;
	int	g;
	int	b;

	r = (((c1 >> 16) & 0xff) + ((c2 >> 16) & 0xff));
	g = (((c1 >> 8) & 0xff) + ((c2 >> 8) & 0xff));
	b = ((c1 & 0xff) + (c2 & 0xff));
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (r << 16 | g << 8 | b);
}

unsigned int	color_mult(unsigned int c1, unsigned int c2)
{
	int	r;
	int	g;
	int	b;

	r = ((c1 >> 16) & 0xff) * ((c2 >> 16) & 0xff) / 0xff;
	g = ((c1 >> 8) & 0xff) * ((c2 >> 8) & 0xff) / 0xff;
	b = (c1 & 0xff) * (c2 & 0xff) / 0xff;
	if (r > 0xff)
		r = 0xff;
	if (g > 0xff)
		g = 0xff;
	if (b > 0xff)
		b = 0xff;
	return (r << 16 | g << 8 | b);
}

unsigned int	color_mean(unsigned int c1, unsigned int c2)
{
	int	r;
	int	g;
	int	b;

	r = (((c1 >> 16) & 0xff) + ((c2 >> 16) & 0xff)) / 2;
	g = (((c1 >> 8) & 0xff) + ((c2 >> 8) & 0xff)) / 2;
	b = ((c1 & 0xff) + (c2 & 0xff)) / 2;
	return (r << 16 | g << 8 | b);
}
