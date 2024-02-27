/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:43:51 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/27 20:26:39 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	getting_new_axis(t_vec *cam, t_vec *h, t_vec *v, t_vec *ax)
{
	h->x = cam->y * ax->z - cam->z * ax->y;
	h->y = cam->z * ax->x - cam->x * ax->y;
	h->z = cam->x * ax->y - cam->y * ax->x;
	v->x = cam->y * h->z - cam->z * h->y;
	v->y = cam->z * h->x - cam->x * h->z;
	v->z = cam->x * h->y - cam->y * h->x;
}

void	get_screen_vec(t_vec *cam, t_vec *x_ax, t_vec *y_ax)
{
	t_vec	axis;

	if (!cam->x && cam->y == 1 && !cam->z)
	{
		axis = vec_new(0, 0, 1);
		getting_new_axis(cam, x_ax, y_ax, &axis);
		opp_vec(x_ax);
		opp_vec(y_ax);
	}
	else
	{
		axis = vec_new(0, 1, 0);
		getting_new_axis(cam, x_ax, y_ax, &axis);
		opp_vec(y_ax);
	}
}

void	throw_rays(t_sc *sc, t_point *start, t_point *ctx, t_point *cty)
{
	t_ray	ray;

	ray.orig.x = start->x + ctx->x * sc->mlx.w + cty->x * sc->mlx.h;
	ray.orig.y = start->y + ctx->y * sc->mlx.w + cty->y * sc->mlx.h;
	ray.orig.z = start->z + ctx->z * sc->mlx.w + cty->z * sc->mlx.h;
	ray_init(&ray);
	all_intersect(sc, &ray);
}
