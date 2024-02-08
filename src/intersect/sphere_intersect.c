/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:58:05 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/08 17:58:55 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	sph_intersect(t_item *item, t_vec *ray)
{
	t_sp	*sp;
	size_t	dist;
	double	disc;

	sp = item->obj;
	disc = exp_2(dot_product(ray, sp[0].pos)) - (dot_product(sp[0].pos) - sp[0].d / 2 );
	if (disc < 0)
		return (-1);
	return (1);
}
