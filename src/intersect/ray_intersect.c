/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:39:31 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/29 22:28:10 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "miniRT.h"

void	ray_init(t_ray *ray)
{
	ray->zero = vec_new(0, 0, 0);	//  point on the screen (most probably not needed in the struct)
	ray->norm = unit_vector(&ray->orig);
//	ray->k1 = dot_prod(&ray->norm, &ray->norm); //??? but it's 1
//	ray->k1 = 1;
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

/*void	all_intersect(t_sc *sc, t_ray *ray)
{
	t_item	*obj;
	t_ray	light;
	double	d;

	obj = sc->objs;
	while (obj)
	{
		obj->intersect(&obj->type, ray, obj);
		obj = obj -> next;
	}
	init_light_ray(&light, sc, ray);
	ray->hit.obst = false;
	d = dist(&light.zero, &light.orig);
	obj = sc->objs;
	while (obj)
	{
		obj->intersect(&obj->type, &light, obj);
		if (light.hit.obst && light.dist < d)
		{
			ray->hit.obst = true;
			break ;
		}
		obj = obj -> next;
	}
	if (ray->dist < MAXFLOAT)
	{
		ray->hit.obj->get_norm(&ray->hit.obj->type, &ray->hit);
		obj_color(&sc->amb, &sc->light, &sc->mlx.color, &ray->hit);
	}
}*/

void	all_intersect(t_sc *sc, t_ray *ray)
{
	t_item	*obj;
	//t_ray	light;
	//double	d;

	obj = sc->objs;
	while (obj)
	{
		obj->intersect(&obj->type, ray, obj);
		obj = obj -> next;
	}
	/*init_light_ray(&light, sc, ray);
	ray->hit.obst = false;
	d = dist(&light.zero, &light.orig);
	obj = sc->objs;
	while (obj)
	{
		obj->intersect(&obj->type, &light, obj);
		if (light.hit.obst && light.dist < d)
		{
			ray->hit.obst = true;
			break ;
		}
		obj = obj -> next;
	}*/
	if (ray->dist < MAXFLOAT)
	{
		ray->hit.obj->get_norm(&ray->hit.obj->type, &ray->hit);
		sc->mlx.color = get_color(&sc->amb, &sc->light, sc->objs, &ray->hit);
		//obj_color(&sc->amb, &sc->light, &sc->mlx.color, &ray->hit);
	}
}
/*
void	init_light_ray(t_ray *light, t_sc *sc, t_ray *ray)
{
	light->orig = sc->light.pos;
	light->zero = ray->hit.p;
	light->norm = substr_vec(&light->orig, &light->zero);
	norm_vector(&light->norm);
	light->dist = MAXFLOAT;
	light->hit.obst = false;
}
*/
void	init_light_ray(t_ray *ray, t_light *light, t_hit *hit)
{
	ray->orig = light->pos;
	ray->zero = hit->p;
	ray->norm = substr_vec(&ray->orig, &ray->zero);
	norm_vector(&ray->norm);
	ray->dist = MAXFLOAT;
	ray->hit.obj = NULL;
	ray->hit.obst = false;
}
