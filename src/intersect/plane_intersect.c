/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:28:21 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/03/08 12:40:24 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	pl_intersect(t_obj *obj, t_ray *ray, t_item *item)
{
	t_pl	*pl;
	double	d;

	pl = obj->pl;
	ray->hit.obst = false;
	d = dot_prod(&ray->norm, &pl->nov);
	if (fabs(d) < 0.00001)
		return ;
	ray->t[0] = (pl->prod - dot_prod(&ray->zero, &pl->nov)) / d;
	if (ray->t[0] <= 0)
		return ;
	ray->p = mult_new(&ray->norm, ray->t[0]);
	ray->p = sum_vec(&ray->zero, &ray->p);
	check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
}

void	pl_get_norm(t_obj *pl, t_hit *hit, t_ray *ray)
{
	(void)ray;
	hit->norm = pl->pl->nov;
	hit->rgb = pl->pl->rgb;
	hit->type = pla;
}
