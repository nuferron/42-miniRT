/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:36:32 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/14 21:41:45 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void	sph_translation(t_obj *obj, t_sc *sc)
{
	translation(&sc->cam.pos, &obj->sp->pos);
}

void	pl_translation(t_obj *obj, t_sc *sc)
{
	translation(&sc->cam.pos, &obj->pl->pos);
}

void	cy_translation(t_obj *obj, t_sc *sc)
{
	translation(&sc->cam.pos, &obj->cy->pos);
}