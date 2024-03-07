/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:50:51 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/03/07 18:42:04 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	init_mlx(t_sc *sc)
{
	t_img	img;

	sc->mlx.init = NULL;
	sc->mlx.win = NULL;
	sc->mlx.init = mlx_init();
	if (!sc->mlx.init)
		return (ft_error_mlx(sc, 0));
	sc->mlx.win = mlx_new_window(sc->mlx.init, WIDTH, HEIGHT, "miniRT");
	if (!sc->mlx.win)
		return (ft_error_mlx(sc, -2));
	ft_memset(&img, 0, sizeof(t_img));
	sc->mlx.img = img;
	sc->mlx.img.ipt = mlx_new_image(sc->mlx.init, WIDTH, HEIGHT);
	if (!sc->mlx.img.ipt)
		return (ft_error_mlx(sc, -3));
	sc->mlx.img.ppt = mlx_get_data_addr(sc->mlx.img.ipt, &sc->mlx.img.bits, \
	&sc->mlx.img.line, &sc->mlx.img.endian);
	sc->mlx.w = 0;
	sc->mlx.h = 0;
	sc->mlx.color = 0;
	return (0);
}

void	maintain_mlx(t_sc *sc)
{
	mlx_hook(sc->mlx.win, 17, 0, ft_exit_mlx, sc);
	mlx_key_hook(sc->mlx.win, ft_key_hook, sc);
	mlx_loop(sc->mlx.init);
}

int	ft_key_hook(int key, t_sc *sc)
{
	if (key == ESC)
		ft_exit_mlx(sc);
	return (0);
}

/* Cleans up and exits in case of error 
flag > -2 - no display, only structure free
flag = -2 - only mlx.init is allocated
flag = -3 - we should destroy the display */
int	ft_error_mlx(t_sc *sc, int flag)
{
	if (flag == -3)
		mlx_destroy_window(sc->mlx.init, sc->mlx.win);
	else if (flag == -2)
		free(sc->mlx.init);
	free_all(sc);
	exit (1);
}

int	ft_exit_mlx(t_sc *sc)
{
	if (sc->mlx.win)
		mlx_destroy_window(sc->mlx.init, sc->mlx.win);
	free_all(sc);
	exit (0);
}
