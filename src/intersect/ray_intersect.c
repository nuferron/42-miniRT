/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:39:31 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/27 18:38:45 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "miniRT.h"

void	ray_init(t_ray *ray)
{
	ray->zero = vec_new(0, 0, 0);	//  point on the screen (most probably not needed in the struct)
	ray->norm = unit_vector(&ray->orig);
//	ray->k1 = dot_prod(&ray->norm, &ray->norm); //??? but it's 1
	ray->k1 = 1;
	ray->dist = MAXFLOAT;
	ray->hit.obj = NULL;
	ray->hit.obst = false;
}

void	check_dist(t_point *p, t_ray *ray, t_item *obj, double dist)
{
	if (dist > ray->dist)
		return ;
	ray->dist = dist;
	ray->hit.p = *p;
	ray->hit.obj = obj;
	ray->hit.obst = true;
}

void	all_intersect(t_sc *sc, t_ray *ray)
{
	t_item	*obj;
//	int i = 0;

	obj = sc->objs;
	while (obj)
	{
		obj->intersect(&obj->type, ray, obj);
		//if (i++ > 1)
		//	exit(1);
		obj = obj -> next;
		

	}
	/*if (ray->dist < MAXFLOAT)
	{
		ray->hit.obj->get_norm(&ray->hit.obj->type, &ray->hit);
		sc->mlx.color = rgb_to_hex(ray->hit.rgb);
	}
	else
		sc->mlx.color = 0;*/
	if (ray->dist < MAXFLOAT)
	{
		sc->mlx.color = 0;
		ray->hit.obj->get_norm(&ray->hit.obj->type, &ray->hit);
		obj_color(&sc->amb, &sc->light, &sc->mlx.color, &ray->hit);
	}
	else
		sc->mlx.color = 0;
}
