/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:58:21 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/01/18 21:38:42 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	draw_scene(t_sc *sc)
{
	while (sc->mlx.x < WIDTH)
	{
		sc->mlx.y = 0;
		while (sc->mlx.y < HEIGHT)
		{
			put_pixel(sc);
			sc->mlx.y++;
		}
		sc->mlx.x++;
	}
	mlx_put_image_to_window(sc->mlx.init, sc->mlx.win, sc->mlx.img.ipt, 0, 0);
}

void	put_pixel(t_sc *sc)
{
	char	*pix;

	sc->mlx.color = 5 ; // =camera_ray(sc, sc->mlx.x, sc->mlx.y)
	pix = sc->mlx.img.ppt + (sc->mlx.img.line * sc->mlx.y + sc->mlx.x * \
	(sc->mlx.img.bits / 8));
	*(int *)pix = sc->mlx.color;
}

