/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:39:31 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/20 22:19:20 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ray_init(t_ray *ray)
{
	ray->zero = vec_new(0, 0, 0);	//  point on the screen (most probably not needed in the struct)
	unit_vector(&ray->orig, &ray->norm);
	/*if (ray->orig.x >= 0 && ray->orig.x <= 0.2 && ray->orig.y >= 0 && ray->orig.y <= 0.2)
		printf("ray normalized: %f, y: %f, z: %f\n", ray->norm.x, ray->norm.y, ray->norm.z); //erase
	*/
	ray->k1 = dot_prod(&ray->norm, &ray->norm);
	ray->dist = MAXFLOAT;
	ray->hit.obj = NULL;
	ray->hit.type = 0;
//	ray->hit.rec = false;
}

void	check_dist(t_point *p, t_ray *ray, t_item *obj, double dist)
{
	if (dist > ray->dist)
		return ;
	ray->dist = dist;
	ray->hit.p = *p;
	ray->hit.obj = obj;
//	ray->hit.rec = true;
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
		ray->hit.obj->get_norm(&ray->hit.obj->type, &ray->hit);
	if (ray->dist < MAXFLOAT)
		sc->mlx.color = 0xFF0000;
	else
		sc->mlx.color = 0x0000FF;
}
