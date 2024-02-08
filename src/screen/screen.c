/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:43:51 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/07 16:30:04 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
int	inter_square(t_vec *ray)
{
	double	x, y = 0;
	double	lambda = 50 / ray->z;

	x = ray->x * lambda;
	y = ray->y * lambda;
	if (x > 400 && x < 600 && y > 400 && y < 600)
		return (1);
	return (0);
}


double	screen_width(double fov)
{
	return (sin(fov * M_PI / 360) * 2 * FOCAL);
}

double	pixel_ratio(double screen)
{
	return (screen / WIDTH);
}
*/
void	get_screen_vec(t_vec *z_ax, t_vec *x_ax, t_vec *y_ax)
{
	x_ax->x = 0;
	x_ax->y = 0;
	x_ax->z = 0;
	if (z_ax->x && z_ax->y && z_ax->z)
	{
		x_ax->x = 1;
		x_ax->y = 1;
		x_ax->z = -(z_ax->x + z_ax->y) / z_ax->z;
	}
	else
	{
		if (!z_ax->x)
			x_ax->x = 1;
		if (!z_ax->y)
			x_ax->y = 1;
		if (!z_ax->z)
			x_ax->z = 1;
	}
	y_ax->x = z_ax->y * x_ax->z - z_ax->z * x_ax->y;
	y_ax->y = z_ax->z * x_ax->x - z_ax->x * x_ax->z;
	y_ax->z = z_ax->x * x_ax->y - z_ax->y * x_ax->x;
}

void	throw_rays(t_sc *sc, t_vec *x, t_vec *y, t_vec *z)
{
	t_point	o;

	o.x = (x->x * sc->screen.width) + (y->x * sc->screen.width);
	o.x =
}

int main()
{
	t_vec	x, y, z;

	z.x = 1;
	z.y = 2;
	z.z = 3;
	get_screen_vec(&z, &x, &y);
	printf("x: x %f\ty %f\tz %f\ny %f\ty %f\tz %f\n", x.x, x.y, x.z, y.x, y.y, y.z);
}