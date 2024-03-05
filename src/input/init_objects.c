/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:41:25 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/05 15:13:11 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

/*It does a realloc of size 1 (kind of) of t_item structures*/
static t_item	*add_obj(t_item *item, t_sc *sc)
{
	t_item	*ret;

	ret = ft_calloc(1, sizeof(t_item));
	if (!ret)
		exit(ft_dprintf(2, ERROR MEM));
	ret->next = NULL;
	if (!item)
		sc->objs = ret;
	else
		item_lstlast(item)->next = ret;
	return (ret);
}

/*It adds a t_sp and sets its variables.
  Returns 1 with fail and 0 with success*/
int	get_sphere(char *line, int i, t_sc *sc)
{
	t_sp	*sp;
	t_item	*obj;

	obj = add_obj(sc->objs, sc);
	sp = malloc(sizeof(t_sp));
	if (!sp)
		exit(ft_dprintf(2, ERROR MEM));
	skip_space(line, &i);
	if (!line[i])
		return (ft_dprintf(2, ERROR LINE "\"%s\"\n", line), 1);
	if (init_vec(&sp->pos, line, &i))
		return (1);
	skip_space(line, &i);
	if (!is_float(&line[i]) || line[i] == ',')
		return (ft_dprintf(2, ERROR LINE "\"%s\"\n", line), 1);
	sp->r = check_range(line, 'p', i) / 2;
	if (sp->r == -1)
		return (1);
	skip_number(line, &i);
	if (!set_rgb(sp->rgb, line, i))
		return (1);
	init_sp(obj, sp);
	return (0);
}

/*It adds a t_pl and sets its variables.
  Returns 1 with fail and 0 with success*/
int	get_plane(char *line, int i, t_sc *sc)
{
	t_pl	*pl;
	t_item	*obj;

	obj = add_obj(sc->objs, sc);
	pl = malloc(sizeof(t_pl));
	if (!pl)
		exit(ft_dprintf(2, ERROR MEM));
	skip_space(line, &i);
	if (!line[i])
		return (ft_dprintf(2, ERROR LINE "\"%s\"\n", line), 1);
	if (init_vec(&pl->pos, line, &i) || init_vec(&pl->nov, line, &i))
		return (1);
	if (vec_mod(&pl->nov) != 1)
		ft_dprintf(2, WARN UNNORM "\"%s\"\n" NORM, line);
	skip_space(line, &i);
	if (!set_rgb(pl->rgb, line, i))
		return (1);
	norm_vector(&pl->nov);
	init_pl(obj, pl);
	return (0);
}

/*It adds a t_cy and sets its variables.
  Returns 1 with fail and 0 with success*/
int	get_cylinder(char *line, int i, t_sc *sc)
{
	t_item	*obj;
	t_cy	*cy;

	obj = add_obj(sc->objs, sc);
	cy = malloc(sizeof(t_cy));
	if (!cy)
		exit(ft_dprintf(2, ERROR MEM));
	if (!skip_space(line, &i) && !line[i])
		return (ft_dprintf(2, ERROR LINE "\"%s\"\n", line), 1);
	if (init_vec(&cy->pos, line, &i) || init_vec(&cy->nov, line, &i))
		return (1);
	if (vec_mod(&cy->nov) != 1 && !skip_space(line, &i))
		ft_dprintf(2, WARN UNNORM "\"%s\"\n" NORM, line);
	cy->r = check_range(line, 'p', i) / 2;
	skip_sp_num_sp(line, &i);
	cy->h = check_range(line, 'p', i);
	if (cy->r == -1 || cy->h == -2)
		return (1);
	if (!skip_number(line, &i) && !set_rgb(cy->rgb, line, i))
		return (1);
	norm_vector(&cy->nov);
	init_cy(obj, cy);
	return (0);
}

/*It adds a t_cy and sets its variables.
  Returns 1 with fail and 0 with success*/
int	get_cone(char *line, int i, t_sc *sc)
{
	t_item	*obj;
	t_co	*co;

	obj = add_obj(sc->objs, sc);
	co = malloc(sizeof(t_co));
	if (!co)
		exit(ft_dprintf(2, ERROR MEM));
	if (!skip_space(line, &i) && !line[i])
		return (ft_dprintf(2, ERROR LINE "\"%s\"\n", line), 1);
	if (init_vec(&co->pos, line, &i) || init_vec(&co->nov, line, &i))
		return (1);
	if (!skip_space(line, &i) && vec_mod(&co->nov) != 1)
		ft_dprintf(2, WARN UNNORM "\"%s\"\n" NORM, line);
	co->r = check_range(line, 'p', i) / 2;
	skip_sp_num_sp(line, &i);
	co->h = check_range(line, 'p', i);
	if (co->r == -1 || co->h == -2)
		return (1);
	if (skip_number(line, &i) && !set_rgb(co->rgb, line, i))
		return (1);
	norm_vector(&co->nov);
	init_cn(obj, co);
	return (0);
}
