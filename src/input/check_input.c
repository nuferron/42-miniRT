/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:05:38 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/05 17:43:31 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

/*It gets the first 5 (non-space like) characters and returns them*/
static void	get_element(char *line, int i, char *tmp)
{
	int	j;

	j = 0;
	while (j < 3 && line[i] && !is_whitespace(line[i]))
		tmp[j++] = line[i++];
	tmp[j] = '\0';
}

/*It checks that the file name ends with ".rt"*/
static int	check_file_type(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ft_strncmp(&file[len - 3], ".rt", 4))
		return (1);
	return (0);
}

/*It reads the first part of the line and calls the correspondig
 function. If no coincidence is found, it throws an error message and
 returns 1*/
static int	check_content(t_sc *sc, char *line)
{
	int		i;
	char	element[4];

	i = 0;
	skip_space(line, &i);
	if (!line[i])
		return (0);
	get_element(line, i, element);
	if (!ft_strncmp(element, "A", 2))
		return (get_ambient(line, ++i, &sc->amb));
	else if (!ft_strncmp(element, "C", 2))
		return (get_camera(line, ++i, &sc->cam));
	else if (!ft_strncmp(element, "L", 2))
		return (get_light(line, ++i, &sc->light));
	else if (!ft_strncmp(element, "sp", 3))
		return (get_sphere(line, i + 2, sc));
	else if (!ft_strncmp(element, "pl", 3))
		return (get_plane(line, i + 2, sc));
	else if (!ft_strncmp(element, "cy", 3))
		return (get_cylinder(line, i + 2, sc));
	else if (!ft_strncmp(element, "cn", 3))
		return (get_cone(line, i + 2, sc));
	else
		return (ft_dprintf(2, ERROR ELEM "%s\n", element), 1);
	return (0);
}

/*It reads the document by lines and calls check_content*/
static int	check_file(int fd, t_sc *sc)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (ft_dprintf(2, ERROR EMPTY), 1);
	while (line)
	{
//		line[ft_strlen(line) - 1] = '\0';
		if (check_content(sc, line))
			exit(1);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

/*It does a preliminary check (arguments and fd)
 and calls the functions to check the file name and the content*/
int	check_input(int argc, char **argv, t_sc *sc)
{
	int	fd;

	if (argc != 2)
		return (ft_dprintf(2, ERROR ARGS), 1);
	if (check_file_type(argv[1]))
		return (ft_dprintf(2, ERROR TYPE), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_dprintf(2, ERROR FNF "%s\n", argv[1]), 1);
	if (check_file(fd, sc))
		return (1);
	if (sc->amb.ratio == -1 || sc->cam.fov == -1 || !sc->light)
		return (ft_dprintf(2, ERROR MUST), 1);
	sc->screen.width = sin(sc->cam.fov / 2) * 2 * FOCAL;
	sc->screen.pix_rat = sc->screen.width / WIDTH;
	sc->screen.height = sc->screen.pix_rat * HEIGHT;
	sc->screen.center = mult_new(&sc->cam.nov, FOCAL);
	get_screen_vec(&sc->cam.nov, &sc->screen.x_ax, &sc->screen.y_ax);
	sc->screen.start.x = sc->screen.center.x + sc->screen.x_ax.x \
		* sc->screen.width / 2 + sc->screen.y_ax.x * sc->screen.height / 2;
	sc->screen.start.y = sc->screen.center.y + sc->screen.x_ax.y \
		* sc->screen.width / 2 + sc->screen.y_ax.y * sc->screen.height / 2;
	sc->screen.start.z = sc->screen.center.z + sc->screen.x_ax.z \
		* sc->screen.width / 2 + sc->screen.y_ax.z * sc->screen.height / 2;
	return (0);
}
