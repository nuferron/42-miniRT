/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:05:38 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/10 17:56:47 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	check_file_type(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ft_strncmp(&file[len - 3], ".rt", 4))
		return (1);
	return (0);
}

static int	check_content(int fd, t_sc *sc, char *line)
{
	int	i;

	i = 0;
	while (ft_iswhitespace(line[i]))
		i++;
	if (!ft_strncmp(&line[i], "A", 2))
		return (get_ambient(line[i], i, sc));
	else if (!ft_strncmp(&line[i], "C", 2))
		return (get_camera(line[i], i, sc));
	else if (!ft_strncmp(&line[i], "L", 2))
		return (get_light(line[i], i, sc));
	else if (!ft_strncmp(&line[i], "sp", 3))
		return (get_sphere(line[i], i, sc));
	else if (!ft_strncmp(&line[i], "pl", 3))
		return (get_plane(line[i], i, sc));
	else if (!ft_strncmp(&line[i], "cy", 2))
		return (get_cylinder(line[i], i, sc));
	else
		return (ft_dprintf(2, LINE, line), free(line), 1);
}

static int	check_file(int fd, t_sc *sc)
{
	(void)fd;
	sc->sp->x = 1;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (ft_dprintf(2, EMPTY), 1);
	while (line)
	{
		if (check_content(fd, sc, line))
			return (1);
		line = get_next_line(fd);
	}
	return (0);
}

int	check_input(int argc, char **argv, t_sc *sc)
{
	int	fd;

	(void)sc;
	if (argc != 2)
		return (ft_dprintf(2, ARGS), 1);
	if (check_file_type(argv[1]))
		return (ft_dprintf(2, TYPE), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_dprintf(2, FNF, argv[1]), 1);
	if (check_file(fd, sc))
		return (1);
	return (0);
}
