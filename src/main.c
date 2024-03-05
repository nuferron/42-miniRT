/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:58:50 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/04 16:55:03 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	init_sc(t_sc *sc)
{
	sc->amb.ratio = -1;
	sc->cam.fov = -1;
	sc->light = NULL;
	sc->objs = NULL;
}

int	main(int argc, char **argv)
{
	static t_sc	sc;

	init_sc(&sc);
	if (check_input(argc, argv, &sc))
		return (1);
	coord_transformation(&sc);
	init_mlx(&sc);
	draw_scene(&sc);
	maintain_mlx(&sc);
	return (0);
}
