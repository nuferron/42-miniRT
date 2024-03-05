/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:43:51 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/04 19:15:25 by nzhuzhle         ###   ########.fr       */
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
	sc->ray.orig.x = start->x + ctx->x * sc->mlx.w + cty->x * sc->mlx.h;
	sc->ray.orig.y = start->y + ctx->y * sc->mlx.w + cty->y * sc->mlx.h;
	sc->ray.orig.z = start->z + ctx->z * sc->mlx.w + cty->z * sc->mlx.h;
	ray_init(&sc->ray);
	all_intersect(sc, &sc->ray);
}

int	check_first_pix(t_sc *sc, t_point *ctx, t_point *cty)
{
	sc->mlx.w = 0;
	sc->mlx.h = 0;
	throw_rays(sc, &sc->screen.start, ctx, cty);
	if (sc->ray.hit.type == pla || dot_prod(&sc->ray.hit.norm, &sc->cam.nov) <= 0)
		return (0);
	printf("WARNING: your camera is inside of an object. Change the position to see the world.\n");
	sc->mlx.color = 0;
	while (++sc->mlx.w < WIDTH)
	{
		sc->mlx.h = -1;
		while (++sc->mlx.h < HEIGHT)
			put_pixel(sc);
	}
	mlx_put_image_to_window(sc->mlx.init, sc->mlx.win, sc->mlx.img.ipt, 0, 0);
	return (1);
}