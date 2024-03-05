/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:58:21 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/03/04 19:15:32 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	draw_scene(t_sc *sc)
{
	t_point	ct_x;
	t_point	ct_y;

	ct_x.x = -(sc->screen.pix_rat) * sc->screen.x_ax.x;
	ct_x.y = -(sc->screen.pix_rat) * sc->screen.x_ax.y;
	ct_x.z = -(sc->screen.pix_rat) * sc->screen.x_ax.z;
	ct_y.x = -(sc->screen.pix_rat) * sc->screen.y_ax.x;
	ct_y.y = -(sc->screen.pix_rat) * sc->screen.y_ax.y;
	ct_y.z = -(sc->screen.pix_rat) * sc->screen.y_ax.z;
	if (check_first_pix(sc, &ct_x, &ct_y))
		return ;
	sc->mlx.w = -1;
	while (++sc->mlx.w < WIDTH)
	{
		sc->mlx.h = -1;
		while (++sc->mlx.h < HEIGHT)
		{
			sc->mlx.color = 0;
			throw_rays(sc, &sc->screen.start, &ct_x, &ct_y);
			put_pixel(sc);
		}
	}
	mlx_put_image_to_window(sc->mlx.init, sc->mlx.win, sc->mlx.img.ipt, 0, 0);
}

void	put_pixel(t_sc *sc)
{
	char	*pix;

	pix = sc->mlx.img.ppt + (sc->mlx.img.line * sc->mlx.h + sc->mlx.w * \
	(sc->mlx.img.bits / 8));
	*(int *)pix = sc->mlx.color;
}
