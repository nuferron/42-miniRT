/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:41:25 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/28 16:10:59 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

/*It adds a t_sp and sets its variables.
  Returns 1 with fail and 0 with success*/
int	get_sphere(char *line, int i, t_sc *sc)
{
	t_sp	*sp;
	t_item	*obj;

	obj = add_obj(sc->objs, sc);
	sp = malloc(sizeof(t_sp));
	if (!sp)
		exit(ft_dprintf(2, MEM));
	skip_space(line, &i);
	if (!line[i])
		return (ft_dprintf(2, LINE, line), 1);
	if (init_vec(&sp->pos, line, &i))
		return (1);
	skip_space(line, &i);
	if (!is_float(&line[i]) || line[i] == ',')
		return (ft_dprintf(2, LINE, line), 1);
	sp->r = ft_atof(&line[i]) / 2;
//	printf("SP radius: %f\n", sp->r);
	skip_number(line, &i);
	if (!set_rgb(sp->rgb, line, i))
		return (1);
	obj->type.sp = sp;
	obj->intersect = sph_intersect;
	obj->trans = sph_translation;
	obj->obj_free = sp_free;
	obj->get_norm = sp_get_norm;
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
		exit(ft_dprintf(2, MEM));
	skip_space(line, &i);
	if (!line[i])
		return (ft_dprintf(2, LINE, line), 1);
	if (init_vec(&pl->pos, line, &i)
		|| init_vec(&pl->nov, line, &i))
		return (1);
	skip_space(line, &i);
	if (!set_rgb(pl->rgb, line, i))
		return (1);
	norm_vector(&pl->nov);
	obj->type.pl = pl;
	obj->intersect = pl_intersect;
	obj->trans = pl_translation;
	obj->obj_free = pl_free;
	obj->get_norm = pl_get_norm;
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
		exit(ft_dprintf(2, MEM));
	skip_space(line, &i);
	if (!line[i])
		return (ft_dprintf(2, LINE, line), 1);
	if (init_vec(&cy->pos, line, &i)
		|| init_vec(&cy->nov, line, &i))
		return (1);
	skip_space(line, &i);
	cy->r = check_range(line, 0, i) / 2;
//	printf("CYL radius: %f\n", cy->r);
	skip_number(line, &i);
	skip_space(line, &i);
	cy->h = check_range(line, 0, i);
	if (cy->r == -2 || cy->h == -2)
		return (1);
	skip_number(line, &i);
	if (!set_rgb(cy->rgb, line, i))
		return (1);
	norm_vector(&cy->nov);
	//printf("coord cyl before: %f, %f, %f\n", cy->pos.x, cy->pos.y, cy->pos.z);
	//printf("coord cyl after: %f, %f, %f\n", cy->pos.x, cy->pos.y, cy->pos.z);
	obj->type.cy = cy;
	obj->intersect = cy_intersect;
	obj->trans = cy_translation;
	obj->obj_free = cy_free;
	obj->get_norm = cy_get_norm;
	return (0);
}

/*It does a realloc of size 1 (kind of) of t_item structures*/
t_item	*add_obj(t_item *item, t_sc *sc)
{
	t_item	*ret;

	ret = ft_calloc(1, sizeof(t_item));
	if (!ret)
		exit(ft_dprintf(2, MEM));
	ret->next = NULL;
	if (!item)
		sc->objs = ret;
	else
		item_lstlast(item)->next = ret;
	return (ret);
}
