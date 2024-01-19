/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:41:25 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/18 18:12:14 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

/*It adds a t_sp and sets its variables.
  Returns 1 with fail and 0 with success*/
int	get_sphere(char *line, int i, t_item *item)
{
	int		id;
	t_sp	*sp;

	id = item->total;
	add_obj(item);
	sp = (t_sp *)item->obj;
	skip_space(line, &i);
	if (!line[i])
		return (ft_dprintf(2, LINE, line), 1);
	if (init_vec(&sp[id].pos, line, &i, 0))
		return (1);
	skip_space(line, &i);
	if (!is_float(&line[i]) || line[i] == ',')
		return (ft_dprintf(2, LINE, line), 1);
	sp[id].d = ft_atof(&line[i]);
	skip_number(line, &i);
	if (!set_rgb(sp[id].rgb, line, i))
		return (1);
	return (0);
}

/*It adds a t_pl and sets its variables.
  Returns 1 with fail and 0 with success*/
int	get_plane(char *line, int i, t_item *item)
{
	int		id;
	t_pl	*pl;

	id = item->total;
	add_obj(item);
	pl = (t_pl *)item->obj;
	skip_space(line, &i);
	if (!line[i])
		return (ft_dprintf(2, LINE, line), 1);
	if (init_vec(&pl[id].pos, line, &i, 0)
		|| init_vec(&pl[id].nov, line, &i, 0))
		return (1);
	skip_space(line, &i);
	if (!set_rgb(pl[id].rgb, line, i))
		return (1);
	return (0);
}

/*It adds a t_cy and sets its variables.
  Returns 1 with fail and 0 with success*/
int	get_cylinder(char *line, int i, t_item *item)
{
	int		id;
	t_cy	*cy;

	id = item->total;
	add_obj(item);
	cy = (t_cy *)item->obj;
	skip_space(line, &i);
	if (!line[i])
		return (ft_dprintf(2, LINE, line), 1);
	if (init_vec(&cy[id].pos, line, &i, 0)
		|| init_vec(&cy[id].nov, line, &i, 0))
		return (1);
	skip_space(line, &i);
	cy[id].d = check_range(line, 0, i);
	skip_number(line, &i);
	skip_space(line, &i);
	cy[id].h = check_range(line, 0, i);
	if (cy[id].d == -2 || cy[id].h == -2)
		return (1);
	skip_number(line, &i);
	if (!set_rgb(cy[id].rgb, line, i))
		return (1);
	return (0);
}

/*It does a realloc of size 1 (kind of) of t_item structures*/
void	add_obj(t_item *item)
{
	void	*ret;

	if (!item->total)
	{
		item->obj = ft_calloc(1, item->size);
		if (!item->obj)
			exit(ft_dprintf(2, MEM));
		item->total++;
		return ;
	}
	ret = ft_calloc(item->total + 1, item->size);
	if (!ret)
		exit(ft_dprintf(2, MEM));
	ft_memmove(ret, item->obj, (item->total * item->size));
	free(item->obj);
	item->obj = ret;
	item->total++;
}
