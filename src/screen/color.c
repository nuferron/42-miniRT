/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:18:22 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/21 19:18:57 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

unsigned int	sep_rgb_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

unsigned int	rgb_to_hex(int *rgb)
{
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

/*unsigned int	color_intensity(int *rgb, float n)
{
	int	r;
	int	g;
	int	b;

	r = rgb[0] * n;
	g = rgb[1] * n;
	b = rgb[2] * n;
	return (r << 16 | g << 8 | b);
}*/

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

/*void	add_color(int *color, int *add)
{
	color[0] += add[0];
	color[1] += add[1];
	color[2] += add[2];
	rerange_rgb(color);
}*/

/*unsigned int	add_color(unsigned int c1, unsigned int c2)
{
	int	r;
	int	g;
	int	b;

	r = (((c1 >> 16) & 0xff) + ((c2 >> 16) & 0xff)) / 2;
	g = (((c1 >> 8) & 0xff) + ((c2 >> 8) & 0xff)) / 2;
	b = ((c1 & 0xff) + (c2 & 0xff)) / 2;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (r << 16 | g << 8 | b);
}*/

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
/*
void	multiply_color(int *color, int *mult)
{
	color[0] = color[0] * mult[0] / 255;
	color[1] = color[1] * mult[1] / 255;
	color[2] = color[2] * mult[2] / 255;
	rerange_rgb(color);
}*/

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
/*
int	main()
{
	unsigned int color;

	color = color_x_fact(0xff0000, 0.3 * 0.1);
	printf("0x%x\n", color);
}*/
