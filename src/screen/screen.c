/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:43:51 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/11 17:04:02 by nuferron         ###   ########.fr       */
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

void	throw_rays(t_sc *sc, t_vec *x, t_vec *y)
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
			ray.ray_orig.x = sc->screen.center.x + i * x->x + j * y->x;
			ray.ray_orig.y = sc->screen.center.y + i * x->y + j * y->y;
			ray.ray_orig.z = sc->screen.center.z + i * x->z + j * y->z;
			unit_vector(&ray.ray_orig, &ray.ray_vec);
			i++;
		}
		j++;
	}
}
/*
int main()
{
	t_sc sc;
	t_vec	nx;
	t_vec	ny;
	
	sc.screen.center.x = 0;
	sc.screen.center.y = 0;
	sc.screen.center.z = 150;
	sc.screen.pix_rat = 0.5;
	sc.screen.width = 5;
	nx.x = 1;
	nx.y = 0;
	nx.z = 0;
	ny.x = 0;
	ny.y = 1;
	ny.z = 0;
	throw_rays(&sc, &nx, &ny);
}*/
