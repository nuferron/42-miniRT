/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:28:21 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/21 19:38:58 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	pl_intersect(t_obj *obj, t_ray *ray, t_item *item)
{
	t_pl	*pl;
	float	d;

	pl = obj->pl;
	d = dot_prod(&ray->norm, &pl->nov);
	ray->t = pl->prod / d;
	if (ray->t <= 0 || fabs(d) < 0.00000001)
		return ;
	ray->p = mult_new(&ray->norm, ray->t);
	check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
//	printf("plane pointer %p, ray pointer %p, item pointer %p\n", obj, ray, item);
}

void	pl_get_norm(t_obj *pl, t_hit *hit)
{
	hit->norm = pl->pl->nov;
	hit->rgb = pl->pl->rgb;
//	printf("plane pointer %p, ray pointer %p\n", pl, hit);
}