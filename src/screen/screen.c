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

int	inter_square(t_ray *ray)
{

}

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
	t_ray	ray;
	int		i;
	int		j;
	int		h;

	j = -sc->screen.pix_rat * HEIGHT;
	h = -j;
	while (j < h)
	{
		i = -sc->screen.width;
		while (i < sc->screen.width)
		{
			ray.ray_orig.x = sc->screen.center.x + i * x.x + j * y.x;
			ray.ray_orig.y = sc->screen.center.y + i * x.y + j * y.y;
			ray.ray_orig.z = sc->screen.center.z + i * x.z + j * y.z;
			unit_vector(&ray.ray_orig, &ray.ray_vec);
			i++;
		}
		j++;
	}
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