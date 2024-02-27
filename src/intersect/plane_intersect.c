/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:28:21 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/27 17:40:11 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	pl_intersect(t_obj *obj, t_ray *ray, t_item *item)
{
	t_pl	*pl;
	float	d;

	pl = obj->pl;
//	if (ray->orig.x >= 0 && ray->orig.x <= 0.2 && ray->orig.y >= 0 && ray->orig.y <= 0.2)
//		printf("[PLANE] POSITION is x: %f, y: %f, z: %f\n", pl->pos.x, pl->pos.y, pl->pos.z); //erase
	d = dot_prod(&ray->norm, &pl->nov);
	ray->t[0] = pl->prod / d;
//	if (ray->orig.x >= 0 && ray->orig.x <= 0.2 && ray->orig.y >= 0 && ray->orig.y <= 0.2)
//		printf("[PLANE] Denom is: %f, PL->prod: %f, t: %f\n", d, pl->prod, ray->t); //erase
	if (ray->t <= 0 || fabs(d) < 0.00001)
		return ;
	ray->p = mult_new(&ray->norm, ray->t[0]);
	check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
//	if (ray->orig.x >= 0 && ray->orig.x <= 0.2 && ray->orig.y >= 0 && ray->orig.y <= 0.2)
//		printf("[PLANE] winning point is x: %f, y: %f, z: %f,   distance is: %f\n", ray->hit.p.x, ray->hit.p.y, ray->hit.p.z, dist(&ray->p, &ray->zero)); //erase
//	printf("plane pointer %p, ray pointer %p, item pointer %p\n", obj, ray, item);
}

void	pl_get_norm(t_obj *pl, t_hit *hit)
{
	hit->norm = pl->pl->nov;
	hit->rgb = pl->pl->rgb;
	hit->type = pla;
//	printf("plane pointer %p, ray pointer %p\n", pl, hit);
}

/* 	flag = 0 - the initial position of the cylinder 
	flag = 1 - the top position of the cylinder */
void	disk_create_check(t_ray *ray, t_cy *cy, int flag)
{
	t_pl	pl;
	t_vec	vec;
	float	d;

	if (!flag)
		pl.pos = cy->pos;
	else
		pl.pos = cy->lim;
//	pl.nov = cy->nov;
	d = dot_prod(&ray->norm, &cy->nov);
	ray->t[0] = cy->prod[0] / d;
	ray->t[1] = cy->prod[1] / d;

//	pl.rgb = cy->rgb;
}