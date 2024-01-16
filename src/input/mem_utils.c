/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:47:10 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/16 17:20:25 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*It frees the structure pointers*/
void	free_all(t_sc *sc)
{
	free(sc->sp.obj);
	free(sc->pl.obj);
	free(sc->cy.obj);
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
