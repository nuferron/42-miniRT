/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:05:38 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/10 15:52:08 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_file_type(char *file)
{
	int	len;

	len = ft_strlen(file);
	printf("\n%s\n", &file[len - 3]);
	if (ft_strncmp(&file[len - 3], ".rt", 4))
		return (1);
	return (0);
}

int	check_input(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (ft_dprintf(2, "%s\n", ARGS), 1);
	fd = open(argv[1], O_RDONLY);
	if (check_file_type(argv[1]))
		return (ft_dprintf(2, "%s\n", TYPE), 1);
	if (fd < 0)
		return (ft_dprintf(2, "%s %s\n", FNF, argv[1]), 1);
	return (0);
}
