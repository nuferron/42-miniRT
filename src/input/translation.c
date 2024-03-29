/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:36:32 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/03/04 16:48:42 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	translation(t_vec *new_origin, t_vec *p)
{
	p->x -= new_origin->x;
	p->y -= new_origin->y;
	p->z -= new_origin->z;
}

void	sph_translation(t_obj *obj, t_sc *sc)
{
	translation(&sc->cam.pos, &obj->sp->pos);
}

void	pl_translation(t_obj *obj, t_sc *sc)
{
	translation(&sc->cam.pos, &obj->pl->pos);
	obj->pl->prod = dot_prod(&obj->pl->pos, &obj->pl->nov);
}

void	cy_translation(t_obj *obj, t_sc *sc)
{
	t_vec	temp;

	translation(&sc->cam.pos, &obj->cy->pos);
	temp = mult_new(&obj->cy->nov, obj->cy->h / 2);
	obj->cy->lim = sum_vec(&obj->cy->pos, &temp);
	obj->cy->pos = substr_vec(&obj->cy->pos, &temp);
	obj->cy->prod[0] = dot_prod(&obj->cy->pos, &obj->cy->nov);
	obj->cy->prod[1] = dot_prod(&obj->cy->lim, &obj->cy->nov);
}

void	cone_translation(t_obj *obj, t_sc *sc)
{
	t_vec	temp;

	translation(&sc->cam.pos, &obj->co->pos);
	temp = mult_new(&obj->co->nov, obj->co->h);
	obj->co->lim = sum_vec(&obj->co->pos, &temp);
	obj->co->prod = dot_prod(&obj->co->lim, &obj->co->nov);
	obj->co->tg = obj->co->r / obj->co->h;
}
