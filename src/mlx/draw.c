/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:58:21 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/11 21:14:50 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	draw_scene(t_sc *sc)
{
	sc->mlx.w = 0;
	while (sc->mlx.w < WIDTH)
	{
		sc->mlx.h = 0;
		while (sc->mlx.h < HEIGHT)
		{
			throw_rays(sc, &sc->screen);
			put_pixel(sc);
			sc->mlx.h++;
		}
		sc->mlx.w++;
	}
	mlx_put_image_to_window(sc->mlx.init, sc->mlx.win, sc->mlx.img.ipt, 0, 0);
}

void	put_pixel(t_sc *sc)
{
	char	*pix;

//	sc->mlx.color = 0x4a5d7d; // =camera_ray(sc, sc->mlx.x, sc->mlx.y)
	pix = sc->mlx.img.ppt + (sc->mlx.img.line * sc->mlx.h + sc->mlx.w * \
	(sc->mlx.img.bits / 8));
	*(int *)pix = sc->mlx.color;
}
