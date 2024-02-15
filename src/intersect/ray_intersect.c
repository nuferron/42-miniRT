/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:39:31 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/15 12:23:34 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ray_init(t_ray *ray)
{
	ray->zero = vec_new(0, 0, 0);	//  point on the screen (most probably not needed in the struct)
	unit_vector(&ray->orig, &ray->norm);
	ray->k1 = dot_prod(&ray->norm, &ray->norm);
	ray->dist = MAXFLOAT;
	ray->hit.obj = NULL;
	ray->hit.type = 0;
	ray->hit.rec = false;
}

void	check_dist(t_point *p, t_ray *ray, double dist)
{
	if (dist > ray->dist)
		return ;
	ray->dist = dist;
	ray->hit.p = *p;
	ray->hit.rec = true;
}

void	memorize(t_obj *obj, t_ray *ray, int type)
{
		ray->hit.obj = obj;
		ray->hit.type = type;
		ray->hit.rec = false;
}

unsigned int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

/*void	obj_color(t_sc *sc, int *color, t_point *hit, t_vec *norm)
{
	double	dot;
	t_vec	hit_l;

	hit_l = substr_vec(hit, &sc->light.pos);
	dot = dot_prod(&hit_l, norm);
	if (dot <= 0)
		*color = 0x000000;
	else
		*color = *color + (sc->light.b * dot * sc->amb.ratio);
}
*/
void	obj_color(t_sc *sc, t_hit *hit, unsigned int *color)
{
	double	dot;
	t_vec	light_ray;

	light_ray = substr_vec(&hit->p, &sc->light.pos);
	dot = dot_prod(&light_ray, &hit->norm);
	if (dot <= 0)
	{
		dprintf(1, "black: x %f\ty %f\tz %f\n", hit->p.x, hit->p.y, hit->p.z);
		*color = 0x000000;
	}
	else
	{
		dprintf(1, "color: x %f\ty %f\tz %f\n", hit->p.x, hit->p.y, hit->p.z);
		*color = *color + (sc->light.b * dot);
	}
}

/*
void	all_intersect(t_sc *sc, t_ray *ray)
{
	t_item	*obj;

<<<<<<< HEAD
	ft_dprintf(2, "all_intersect\n");
	sph_intersect(&((t_sp *)sc->sp.obj)[0], ray);
	sp0 = &((t_sp *)sc->sp.obj)[0];
	sc->mlx.color = create_rgb(sp0->rgb[0], sp0->rgb[1], sp0->rgb[2]);
	dprintf(2, "ray->hit x %f\ty %f\tz %f\n", ray->hit.x, ray->hit.y, ray->hit.z);
	dprintf(2, "sp0->pos x %f\ty %f\tz %f\n", sp0->pos.x, sp0->pos.y, sp0->pos.z);
	if (ray->dist < MAXFLOAT)
	{
		ray->hit_vec = substr_vec(&ray->hit, &sp0->pos);
		exit(1);
		norm_vector(&ray->hit_vec);
		obj_color(sc, &sc->mlx.color, &ray->hit_vec, &ray->norm);
	}
	if (ray->dist < MAXFLOAT)
		sc->mlx.color = 0xFF0000;
	else
		sc->mlx.color = 0x000000;
		sc->mlx.color = 0x0000FF;
}*/

/*void	all_intersect(t_sc *sc, t_ray *ray)
{
	t_item	*obj;

	obj = sc->objs;
	while (obj)
	{
		obj->intersect(&obj->type, ray);
		obj = obj -> next;
	}
	if (ray->hit.type == 2)
		sp_get_norm(ray->hit.obj->sp, ray);
	if (ray->dist < MAXFLOAT)
	{
		//dprintf(2, "hit p: x %f\ty %f\tz %f\n", ray->hit.p.x, ray->hit.p.y, ray->hit.p.z);
		int color = 0x00FF00;
		obj_color(sc, &ray->hit, color);
	}
	else
		sc->mlx.color = 0x0000FF;
}*/

void	all_intersect(t_sc *sc, t_ray *ray)
{
	t_item	*obj;

	obj = sc->objs;
	while (obj)
	{
		obj->intersect(&obj->type, ray);
		if (ray->hit.type == 2)
			sp_get_norm(ray->hit.obj->sp, ray);
		if (ray->dist < MAXFLOAT)
		{
			sc->mlx.color = 0x00FF00;
			obj_color(sc, &ray->hit, &sc->mlx.color);
		}
		else
			sc->mlx.color = 0x0000FF;
		obj = obj->next;
	}
}
