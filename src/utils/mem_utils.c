/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:47:10 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/07 18:54:30 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*It frees the structure pointers*/
void	free_all(t_sc *sc)
{
	t_item	*temp;

	while (sc->objs)
	{
		temp = sc->objs;
		temp->obj_free(&temp->type);
		sc->objs = temp->next;
		free(temp);
	}
}

void	sp_free(t_obj *obj)
{
	if (obj->sp)
		free(obj->sp);
}

void	pl_free(t_obj *obj)
{
	if (obj->pl)
		free(obj->pl);
}

void	cy_free(t_obj *obj)
{
	if (obj->cy)
		free(obj->cy);
}

void	cone_free(t_obj *obj)
{
	if (obj->co)
		free(obj->co);
}
