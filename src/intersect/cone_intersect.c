/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:28:24 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/03/07 18:35:19 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	cone_intersect(t_obj *obj, t_ray *ray, t_item *item)
{
	t_vars	var;
	t_co	*co;
	double	dn;
	double	posn;

	co = obj->co;
	var.oc = substr_vec(&ray->zero, &co->pos);
	dn = dot_prod(&co->nov, &ray->norm);
	var.k1 = 1 - (1 + co->tg * co->tg) * dn * dn;
	posn = dot_prod(&co->nov, &var.oc);
	var.k2 = 2 * (dot_prod(&ray->norm, &var.oc) - (1 + co->tg * co->tg) * dn * posn);
	var.k3 = dot_prod(&var.oc, &var.oc) - (1 + co->tg * co->tg) * posn * posn;
	cone_check_disk(ray, co, item, &dn);
	if (!count_t(ray, &var))
		return ;
//	printf("discr: %f\n", var.discr);
	/*if (ray->orig.x >= 0 && ray->orig.x <= 0.2 && ray->orig.y >= 0 && ray->orig.y <= 0.2) 
	{
		printf("discr: %f\n", var.discr);
		printf("[CYLINDER]: cylinder point: x: %f, y: %f, z: %f,    ", ray->p.x, ray->p.y, ray->p.z); //erase
		printf("[CYLINDER]: winning point: x: %f, y: %f, z: %f,    ", ray->hit.p.x, ray->hit.p.y, ray->hit.p.z); //erase
		printf("distance to cylinder point: %f\n", dist(&ray->p, &ray->zero)); //erase
	}*/
	co->m[0] = (ray->t[0] * dn + posn);
	co->m[1] = (ray->t[1] * dn + posn);
	cone_check_body(ray, item, co);
	/*if (ray->orig.x >= 0 && ray->orig.x <= 0.2 && ray->orig.y >= 0 && ray->orig.y <= 0.2) 
	{
		printf("[CYLINDER]: cylinder point: x: %f, y: %f, z: %f,    ", ray->p.x, ray->p.y, ray->p.z); //erase
		printf("[CYLINDER]: winning point: x: %f, y: %f, z: %f,    ", ray->hit.p.x, ray->hit.p.y, ray->hit.p.z); //erase
		printf("distance to cylinder point: %f\n", dist(&ray->p, &ray->zero)); //erase
	}*/
//	printf("cylinder pointer %p, ray pointer %p, item pointer %p\n", obj, ray, item);
}

void	cone_check_body(t_ray *ray, t_item *item, t_co *co)
{
	ray->hit.obst = false;
	if (ray->t[0] > 0 && co->m[0] < co->h && co->m[0] > 0) // what do we do if the intrsection is in the zero point???
	{
		ray->p = mult_new(&ray->norm, ray->t[0]);
		ray->p = sum_vec(&ray->zero, &ray->p);
		check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
	}
//	if (ray->t[0] == ray->t[1])
//		return ;
	if (ray->t[1] > 0 && co->m[1] < co->h  && co->m[1] > 0 && ray->t[0] != ray->t[1])
	{
		ray->p = mult_new(&ray->norm, ray->t[1]);
		ray->p = sum_vec(&ray->zero, &ray->p);
		check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
	}
	if (ray->hit.obst == true)
		ray->hit.type = cone;
	/*if (ray->orig.x >= 0 && ray->orig.x <= 0.2 && ray->orig.y >= 0 && ray->orig.y <= 0.2) 
	{
		printf("res: %i\n", res);
	}*/
}

void	cone_check_disk(t_ray *ray, t_co *co, t_item *item, double *dn)
{
	double	d;
	bool	temp;

	temp = ray->hit.obst;
	ray->hit.obst = false;
	ray->t[0] = (co->prod - dot_prod(&ray->zero, &co->nov)) / *dn;
	if (ray->t[0] > 0)
	{
		ray->p = mult_new(&ray->norm, ray->t[0]);
		ray->p = sum_vec(&ray->zero, &ray->p);
		d = dist(&co->lim, &ray->p);
		if (d <= co->r)
			check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
	}
	if (ray->hit.obst == true)
		ray->hit.type = disk;
	if (temp == true)
		ray->hit.obst = true;
/*	if (ray->orig.x >= 0 && ray->orig.x <= 0.2 && ray->orig.y >= 0 && ray->orig.y <= 0.2) 
	{
		printf("[DISK]: cylinder point: x: %f, y: %f, z: %f,    ", ray->p.x, ray->p.y, ray->p.z); //erase
		printf("[DISK]: winning point: x: %f, y: %f, z: %f,    ", ray->hit.p.x, ray->hit.p.y, ray->hit.p.z); //erase
		printf("distance to DISK point: %f\n", dist(&ray->p, &ray->zero)); //erase
		
	}*/
}


void	cone_get_norm(t_obj *co, t_hit *hit, t_ray *ray)
{
	t_vec	mvec;
	double	a;

	(void)ray;
	hit->rgb = co->co->rgb;
	if (hit->type == disk)
	{
		hit->norm = co->co->nov;
//		hit->norm = mult_new(&co->co->nov, -1);
		return ;
	}
	mvec = substr_vec(&hit->p, &co->co->pos);
	a = (1 + co->co->tg * co->co->tg) * co->co->m[0];
	hit->norm = mult_new(&co->co->nov, a);
	hit->norm = substr_vec(&mvec, &hit->norm);
	if (dot_prod(&hit->norm, &mvec) != 0)
	{
		a = (1 + co->co->tg * co->co->tg) * co->co->m[1];
		hit->norm = mult_new(&co->co->nov, a);
		hit->norm = substr_vec(&mvec, &hit->norm);
	}
	norm_vector(&hit->norm);
//	printf("cylinder pointer %p, ray pointer %p\n", cy, hit);
}
