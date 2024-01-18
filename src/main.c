/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:58:50 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/18 17:45:34 by nuferron         ###   ########.fr       */
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
	if (check_input(argc, argv, &sc))
		return (1);
	printf("main: L pos x %f\n", sc.light.pos.x);
	printf("main: C pos x %f\n", sc.cam.pos.x);
	coord_transformation(&sc);
	printf("main: L pos x %f\n", sc.light.pos.x);
	printf("main: C pos x %f\n", sc.cam.pos.x);
	free_all(&sc);
	return (0);
}
