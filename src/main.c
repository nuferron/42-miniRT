/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:58:50 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/07 16:43:36 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_sc(t_sc *sc)
{
	sc->amb.ratio = -1;
	sc->cam.fov = -1;
	sc->light.b = -1;
	sc->sp.obj = NULL;
	sc->pl.obj = NULL;
	sc->cy.obj = NULL;
	sc->sp.size = sizeof(t_sp);
	sc->pl.size = sizeof(t_pl);
	sc->cy.size = sizeof(t_cy);
	sc->sp.total = 0;
	sc->pl.total = 0;
	sc->cy.total = 0;
}

int	main(int argc, char **argv)
{
	static t_sc	sc;

	init_sc(&sc);
	//printf("mlx %zu\ncam %zu\namb %zu\nli %zu\nit %zu\nscr %zu\n", sizeof(t_mlx), sizeof(t_cam), sizeof(t_amb), sizeof(t_light), sizeof(t_item), sizeof(t_screen));
	if (check_input(argc, argv, &sc))
		return (1);
	printf("main: L pos x %f\n", sc.light.pos.x);

	printf("main: C pos x %f\n", sc.cam.pos.x);
	coord_transformation(&sc);
	printf("main: L pos x %f\n", sc.light.pos.x);
	printf("main: C pos x %f\n", sc.cam.pos.x);
  	init_mlx(&sc);
	draw_scene(&sc);
	maintain_mlx(&sc);
  //	free_all(&sc); // don't think we need it, I do it in ft_exit_mlx as a reaction to the keys
	return (0);
}
