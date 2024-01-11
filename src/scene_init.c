/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:37:09 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/10 22:10:29 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*it checks if the range is correct. If it is, it returns the value,
  otherwise, it returns -2.
  a=amb.ratio / f=cam.fov / c=*rgb / v=*.vxyz*/
float	check_range(char *line, char type, int i)
{
	float	rg[2];
	float	input;

	if (!is_number(&line[i]) || line[i] == ',')
		return (ft_dprintf(2, "CR -> "LINE, line), -2);
	rg[0] = 0.0;
	rg[1] = 1.0;
	if (type == 'v')
		rg[0] = -1.0;
	else if (type == 'f')
		rg[1] = 180;
	else if (type == 'c')
		rg[1] = 255;
	input = ft_atof(&line[i]);
	if (input < rg[0] || input > rg[1])
		return (ft_dprintf(2, RANGE, line, (int)rg[0], (int)rg[1]), -2);
	return (input);
}

/*It sets the variable rgb to its value.
  Returns 0 when fails + displays an error message*/
int	set_rgb(int *rgb, char *line, int i)
{
	int	j;

	j = 0;
	if (!line[i])
		return (0);
	while (j < 3)
	{
		while (is_whitespace(line[i]))
			i++;
		if (!line[i])
			return (0);
		rgb[j] = (int)check_range(line, 'c', i);
		if (rgb[j++] == -2 || !is_number(&line[i]))
			return (0);
		while (ft_isdigit(line[i]))
			i++;
		if (line[i] == ',')
			i++;
	}
	return (1);
}

/*It sets all t_amb variables. Returns 1 with fail and 0 with success*/
int	get_ambient(char *line, int i, t_sc *sc)
{
	t_amb	*ambient;

	if (sc->amb)
		return (ft_dprintf(2, REPE, "A"), free_all(sc), 1);
	while (is_whitespace(line[i]))
		i++;
	if (!line[i])
		return (ft_dprintf(2, LINE, line), free(line), 1);
	ambient = ft_calloc(1, sizeof(t_amb));
	if (!ambient)
		exit(ft_dprintf(2, MEM));
	sc->amb = ambient;
	sc->amb->ratio = check_range(line, 'a', i);
	if (sc->amb->ratio == -2)
		return (free(line), free_all(sc), 1);
	while (line[i] && !is_whitespace(line[i]))
		i++;
	if (!set_rgb(sc->amb->rgb, line, i))
		return (free(line), free_all(sc), 1);
	return (free(line), 0);
}
/*
int	get_camera(char *line, int i, t_sc *sc)
{
	t_cam	*camera;

	if (sc->amb)
		return (ft_dprintf(2, REPE, "C"), free_all(sc, line), 1);
	while (is_whitespace(line[i]))
		i++;
	if (!line[i])
		return (ft_dprintf(2, LINE, line), free(line), 1);
	camera = ft_calloc(1, sizeof(t_cam));
	if (!camera)
		exit(ft_dprintf(2, MEM));
	sc->cam = camera;

}*/
