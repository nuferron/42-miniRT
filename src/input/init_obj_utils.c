/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:06:57 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/06 16:27:55 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	init_sp(t_item *obj, t_sp *sp)
{
	obj->type.sp = sp;
	obj->intersect = sph_intersect;
	obj->trans = sph_translation;
	obj->obj_free = sp_free;
	obj->get_norm = sp_get_norm;
}

void	init_pl(t_item *obj, t_pl *pl, char *line)
{
	(void)line;
	norm_vector(&pl->nov);
	obj->type.pl = pl;
	obj->intersect = pl_intersect;
	obj->trans = pl_translation;
	obj->obj_free = pl_free;
	obj->get_norm = pl_get_norm;
}

void	init_cy(t_item *obj, t_cy *cy, char *line)
{
	(void)line;
	norm_vector(&cy->nov);
	obj->type.cy = cy;
	obj->intersect = cy_intersect;
	obj->trans = cy_translation;
	obj->obj_free = cy_free;
	obj->get_norm = cy_get_norm;
}

void	init_cn(t_item *obj, t_co *co, char *line)
{
	float	n;

	n = vec_mod(&co->nov);
	if (n && n != 1)
	{
		ft_dprintf(2, WARN UNNORM "\"%s\"\n" NORM, line);
		norm_vector(&co->nov);
	}
	else if (!n)
		ft_dprintf(2, WARN BLIND);
	obj->type.co = co;
	obj->intersect = cone_intersect;
	obj->trans = cone_translation;
	obj->obj_free = cone_free;
	obj->get_norm = cone_get_norm;
}
