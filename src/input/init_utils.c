/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:10:53 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/07 19:12:36 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static int	put_vec(char *line, int *i, double *coord)
{
	if (!line[*i])
		return (ft_dprintf(2, ERROR PARAM "\"%s\"\n", line), -2);
	if (!is_float(&line[*i]))
		return (ft_dprintf(2, ERROR LINE "\"%s\"\n", line), -2);
	*coord = ft_atof(&line[*i]);
	if (int_len(*coord) >= 5)
		ft_dprintf(2, WARN BIG "\"%s\"\n" REC, line);
	if (line[*i] == '+' || line[*i] == '-')
		(*i)++;
	while (line[*i] && ft_isdigit(line[*i]))
		(*i)++;
	if (line[*i] == '.' && ft_isdigit(line[*i + 1]))
		(*i)++;
	while (line[*i] && ft_isdigit(line[*i]))
		(*i)++;
	return (0);
}

/*It initializes a t_vec and displays an error if something's wrong*/
int	init_vec(t_vec *vec, char *line, int *i)
{
	int	r;

	skip_space(line, i);
	r = put_vec(line, i, &vec->x);
	if (r)
		return (-2);
	if (line[*i] == ',')
		(*i)++;
	r = put_vec(line, i, &vec->y);
	if (r)
		return (-2);
	if (line[*i] == ',')
		(*i)++;
	r = put_vec(line, i, &vec->z);
	if (r)
		return (-2);
	if (!is_whitespace(line[*i]))
		return (ft_dprintf(2, ERROR LINE "\"%s\"\n", line), -2);
	return (0);
}

/*it checks if the range is correct. If it is, it returns the value,
  otherwise, it returns -2.
  a=amb.ratio / f=cam.fov / c=rgb */
double	check_range(char *line, char type, int i)
{
	float	rg[2];
	double	input;

	if (!line[i])
		return (ft_dprintf(2, ERROR PARAM "\"%s\"\n", line), -2);
	if (!is_float(&line[i]) || line[i] == ',')
		return (ft_dprintf(2, ERROR LINE "\"%s\"\n", line), -2);
	rg[0] = 0.0;
	rg[1] = 1.0;
	if (type == 'f')
		rg[1] = 180;
	else if (type == 'c')
		rg[1] = 255;
	input = ft_atof(&line[i]);
	if (input <= 0 && type == 'p')
		return (ft_dprintf(2, ERROR SIZE "\"%s\"\n", line), -2);
	if (type && type != 'p' && (input < rg[0] || input > rg[1]))
		return (ft_dprintf(2, ERROR RANGE "([%d - %d]):\n\"%s\"\n",
				(int)rg[0], (int)rg[1], line), -2);
	if (int_len(input) >= 5)
		ft_dprintf(2, WARN BIG "\"%s\"\n" REC, line);
	return (input);
}

/*It sets the variable rgb to its value.
  Returns 0 when fails + displays an error message*/
int	set_rgb(int *rgb, char *line, int i)
{
	int		j;
	float	fl;

	j = -1;
	if (!skip_space(line, &i) && !line[i])
		return (ft_dprintf(2, ERROR PARAM "\"%s\"\n", line), 0);
	while (++j < 3)
	{
		if (!line[i])
			return (ft_dprintf(2, ERROR PARAM "\"%s\"\n", line), 0);
		fl = check_range(line, 'c', i);
		if (fl == -2)
			return (0);
		if (fl != (int)fl)
			return (ft_dprintf(2, ERROR INT "\"%s\"\n", line), 0);
		rgb[j] = (int)fl;
		while (ft_isdigit(line[i]))
			i++;
		if (j < 2 && line[i] == ',')
			i++;
	}
	if (!skip_space(line, &i) && line[i])
		return (ft_dprintf(2, ERROR PARAM "\"%s\"\n", line), 0);
	return (1);
}

void	coord_transformation(t_sc *sc)
{
	t_item	*obj;
	t_light	*light;

	light = sc->light;
	while (light)
	{
		translation(&sc->cam.pos, &light->pos);
		light = light->next;
	}
	obj = sc->objs;
	while (obj)
	{
		obj->trans(&(obj->type), sc);
		obj = obj->next;
	}
	translation(&sc->cam.pos, &sc->cam.pos);
}
