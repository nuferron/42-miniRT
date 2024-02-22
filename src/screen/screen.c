/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:43:51 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/22 20:02:48 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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

void	throw_rays(t_sc *sc, t_screen *pic)
{
	t_ray	ray;

	ray.orig.x = pic->start.x + -pic->w_vec.x * pic->pix_rat * sc->mlx.w \
				+ -pic->h_vec.x * pic->pix_rat * sc->mlx.h;
	ray.orig.y = pic->start.y + -pic->w_vec.y * pic->pix_rat * sc->mlx.w \
				+ -pic->h_vec.y * pic->pix_rat * sc->mlx.h;
	ray.orig.z = pic->start.z + -pic->w_vec.z * pic->pix_rat * sc->mlx.w \
				+ -pic->h_vec.z * pic->pix_rat * sc->mlx.h;
	ray_init(&ray);
	all_intersect(sc, &ray);
}
