/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:10:53 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/18 18:06:59 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

/*It initializes a variable of type t_vec*/
int	init_vec(t_vec *vec, char *line, int *i, char t)
{
	skip_space(line, i);
	vec->x = check_range(line, t, *i);
	if (vec->x == -2)
		return (1);
	while (line[*i] && line[*i] != ',')
		(*i)++;
	(*i)++;
	vec->y = check_range(line, t, *i);
	if (vec->y == -2)
		return (1);
	while (line[*i] && line[*i] != ',')
		(*i)++;
	(*i)++;
	vec->z = check_range(line, t, *i);
	if (vec->z == -2)
		return (1);
	while (line[*i] && !is_whitespace(line[*i]))
		(*i)++;
	if (!line[*i])
		return (ft_dprintf(2, PARAM, line), 1);
	return (0);
}

/*it checks if the range is correct. If it is, it returns the value,
  otherwise, it returns -2.
  a=amb.ratio / f=cam.fov / c=*rgb / n=*nov */
float	check_range(char *line, char type, int i)
{
	float	rg[2];
	float	input;

	if (!line[i])
		return (ft_dprintf(2, PARAM, line), -2);
	if (!is_float(&line[i]) || line[i] == ',')
		return (ft_dprintf(2, LINE, line), -2);
	rg[0] = 0.0;
	rg[1] = 1.0;
	if (type == 'n')
		rg[0] = -1.0;
	else if (type == 'f')
		rg[1] = 180;
	else if (type == 'c')
		rg[1] = 255;
	input = ft_atof(&line[i]);
	if (type && (input < rg[0] || input > rg[1]))
		return (ft_dprintf(2, RANGE, &line[i], (int)rg[0], (int)rg[1]), -2);
	return (input);
}

/*It sets the variable rgb to its value.
  Returns 0 when fails + displays an error message*/
int	set_rgb(int *rgb, char *line, int i)
{
	int	j;

	j = 0;
	skip_space(line, &i);
	if (!line[i])
		return (ft_dprintf(2, PARAM, line), 0);
	while (j < 3)
	{
		if (!line[i])
			return (ft_dprintf(2, PARAM, line), 0);
		if (line[i] == '.')
			return (ft_dprintf(2, INT, line), 0);
		rgb[j] = (int)check_range(line, 'c', i);
		if (rgb[j++] == -2 || !is_float(&line[i]))
			return (0);
		while (ft_isdigit(line[i]))
			i++;
		i++;
	}
	skip_space(line, &i);
	if (line[i])
		return (ft_dprintf(2, PARAM, line), 0);
	return (1);
}

static void	translation(t_vec *new_origin, t_vec *p)
{
	p->x -= new_origin->x;
	p->y -= new_origin->y;
	p->z -= new_origin->z;
}

void	coord_transformation(t_sc *sc)
{
	int		i;
	t_sp	*sp;
	t_pl	*pl;
	t_cy	*cy;

	translation(&sc->cam.pos, &sc->light.pos);
	sp = sc->sp.obj;
	pl = sc->pl.obj;
	cy = sc->cy.obj;
	i = -1;
	while (++i < sc->sp.total)
		translation(&sc->cam.pos, &sp->pos);
	i = -1;
	while (++i < sc->pl.total)
		translation(&sc->cam.pos, &pl->pos);
	i = -1;
	while (++i < sc->cy.total)
		translation(&sc->cam.pos, &cy->pos);
	translation(&sc->cam.pos, &sc->cam.pos);
}
