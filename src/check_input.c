/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:05:38 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/10 14:49:47 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_input(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (ft_dprintf(2, "%s%s%s\n", RED, ARGS, RESET), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_dprintf(2, "%s%s%s\n", RED, FILE_NOT_FOUND, RESET), 1);
	return (0);
}
