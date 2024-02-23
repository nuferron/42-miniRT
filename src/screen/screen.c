/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:43:51 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/23 17:34:51 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	get_screen_vec(t_vec *cam, t_vec *x_ax, t_vec *y_ax)
{
	t_vec	axis;

	axis = vec_new(0, -1, 0);
	x_ax->x = cam->y * axis.z - cam->z * axis.y;
	x_ax->y = cam->z * axis.x - cam->x * axis.z;
	x_ax->z = cam->x * axis.y - cam->y * axis.x;
	y_ax->x = cam->y * x_ax->z - cam->z * x_ax->y;
	y_ax->y = cam->z * x_ax->x - cam->x * x_ax->z;
	y_ax->z = cam->x * x_ax->y - cam->y * x_ax->x;
}

/*void	throw_rays(t_sc *sc, t_screen *pic)
{
	t_ray	ray;

	ray.orig.x = pic->start.x + -pic->x_ax.x * pic->pix_rat * sc->mlx.w
				+ -pic->y_ax.x * pic->pix_rat * sc->mlx.h;
	ray.orig.y = pic->start.y + -pic->x_ax.y * pic->pix_rat * sc->mlx.w
				+ -pic->y_ax.y * pic->pix_rat * sc->mlx.h;
	ray.orig.z = pic->start.z + -pic->x_ax.z * pic->pix_rat * sc->mlx.w
				+ -pic->y_ax.z * pic->pix_rat * sc->mlx.h;
	ray_init(&ray);
	all_intersect(sc, &ray);
}*/

void	throw_rays(t_sc *sc, t_point *start, t_point *ctx, t_point *cty)
{
	t_ray	ray;

	ray.orig.x = start->x + ctx->x * sc->mlx.w + cty->x *sc->mlx.h;
	ray.orig.y = start->y + ctx->y * sc->mlx.w + cty->y *sc->mlx.h;
	ray.orig.z = start->z + ctx->z * sc->mlx.w + cty->z *sc->mlx.h;
	ray_init(&ray);
	all_intersect(sc, &ray);
}
