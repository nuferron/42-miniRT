/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:36:32 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/28 15:08:55 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	sph_translation(t_obj *obj, t_sc *sc)
{
//	printf("[SPH TRANSLATION] initial point  x: %f, y: %f, z: %f\n", obj->sp->pos.x, obj->sp->pos.y, obj->sp->pos.z); //erase
	translation(&sc->cam.pos, &obj->sp->pos);
//	printf("[SPH TRANSLATION] final point  x: %f, y: %f, z: %f, radius: %f\n", obj->sp->pos.x, obj->sp->pos.y, obj->sp->pos.z, obj->sp->r); //erase
}

void	pl_translation(t_obj *obj, t_sc *sc)
{
//	printf("[PL TRANSLATION] initial point  x: %f, y: %f, z: %f\n", obj->pl->pos.x, obj->pl->pos.y, obj->pl->pos.z); //erase
	translation(&sc->cam.pos, &obj->pl->pos);
	obj->pl->prod = dot_prod(&obj->pl->pos, &obj->pl->nov);
//	printf("[PL TRANSLATION] final point  x: %f, y: %f, z: %f\n", obj->pl->pos.x, obj->pl->pos.y, obj->pl->pos.z); //erase
}

void	cy_translation(t_obj *obj, t_sc *sc)
{
	t_vec	temp;

//	printf("[CYLINDER TRANSLATION] initial point  x: %f, y: %f, z: %f\n", obj->cy->pos.x, obj->cy->pos.y, obj->cy->pos.z); //erase
	translation(&sc->cam.pos, &obj->cy->pos);
//	printf("[CYLINDER TRANSLATION] point after translation x: %f, y: %f, z: %f\n", obj->cy->pos.x, obj->cy->pos.y, obj->cy->pos.z); //erase
	temp = mult_new(&obj->cy->nov, obj->cy->h / 2);
	obj->cy->lim = sum_vec(&obj->cy->pos, &temp);
	obj->cy->pos = substr_vec(&obj->cy->pos, &temp);
	obj->cy->prod[0] = dot_prod(&obj->cy->pos, &obj->cy->nov);
	obj->cy->prod[1] = dot_prod(&obj->cy->lim, &obj->cy->nov);
//	printf("[CYLINDER TRANSLATION] position point  x: %f, y: %f, z: %f\n", obj->cy->pos.x, obj->cy->pos.y, obj->cy->pos.z); //erase
//	printf("[CYLINDER TRANSLATION] lim point  x: %f, y: %f, z: %f\n", obj->cy->lim.x, obj->cy->lim.y, obj->cy->lim.z); //erase
}
