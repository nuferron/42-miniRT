/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:39:31 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/03/07 18:20:01 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "color.h"

void	ray_init(t_ray *ray)
{
	ray->zero = vec_new(0, 0, 0);
	ray->norm = unit_vector(&ray->orig);
	ray->dist = MAXFLOAT;
	ray->hit.obj = NULL;
	ray->hit.obst = false;
}

void	init_light_ray(t_ray *ray, t_light *light, t_hit *hit)
{
	ray->orig = light->pos;
	ray->zero = hit->p;
	ray->norm = substr_vec(&ray->orig, &ray->zero);
	norm_vector(&ray->norm);
	ray->dist = MAXFLOAT;
	ray->hit.obj = NULL;
}

void	check_dist(t_point *p, t_ray *ray, t_item *obj, double dist)
{
	if (dist > ray->dist || dist < 0.001)
		return ;
	ray->dist = dist;
	ray->hit.p = *p;
	ray->hit.obj = obj;
	ray->hit.obst = true;
}

void	all_intersect(t_sc *sc, t_ray *ray)
{
	t_item	*obj;

	obj = sc->objs;
	while (obj)
	{
		obj->intersect(&obj->type, ray, obj);
		obj = obj -> next;
	}
	if (ray->dist < MAXFLOAT)
	{
		ray->hit.obj->get_norm(&ray->hit.obj->type, &ray->hit, ray);
		if (ray->hit.type == pla)
		{
			if (dot_prod(&ray->norm, &ray->hit.norm) > 0)
				ray->hit.norm = mult_new(&ray->hit.norm, -1);
		}
		get_color(sc, sc->objs, &ray->hit);
	}
}
