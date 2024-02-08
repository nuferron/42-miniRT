/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:23:44 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/01 19:17:53 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	intersection_sp(t_item *item, t_vec *ray)
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
