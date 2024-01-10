/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:58:50 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/10 20:45:27 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_sc	sc;

	if (check_input(argc, argv, &sc))
		return (1);
	//printf("main: sc sp x %f\n", sc.sp->x);
	return (0);
}
