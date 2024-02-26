/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:53:10 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/26 17:06:58 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	cy_intersect(t_obj *obj, t_ray *ray, t_item *item)
{
	t_vars	var;
	t_cy	*cy;
	float	dn;
	float	posn;
	double	k3;

	cy = obj->cy;
	var.oc = substr_vec(&ray->zero, &cy->pos);
	dn = dot_prod(&cy->nov, &ray->norm);
	ray->k1 = 1 - dn * dn;
	posn = dot_prod(&cy->nov, &var.oc);
	var.k2 = 2 * (dot_prod(&ray->norm, &var.oc) - dn * posn);
	k3 = dot_prod(&cy->pos, &cy->pos) - posn * posn - cy->r * cy->r;
	var.discr = var.k2 * var.k2 - 4 * ray->k1 * k3;
	if (var.discr < 0)
		return ; // no intersections
	var.discr = sqrt(var.discr);
	ray->t = (-var.k2 + var.discr) / (2 * ray->k1);
	cy->m[0] = (ray->t * dn + posn);
	if (ray->t > 0 && cy->m[0] < cy->h && cy->m[0] > 0) // what do we do if the intrsection is in the zero point???
	{
		ray->p = mult_new(&ray->norm, ray->t);
		check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
	}
	ray->t = (-var.k2 - var.discr) / (2 * ray->k1);
	cy->m[1] = (ray->t * dn + posn);
	if (var.discr && ray->t > 0 && cy->m[1] < cy->h  && cy->m[1] > 0)
	{
		ray->p = mult_new(&ray->norm, ray->t);
		check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
	}
	if (ray->orig.x >= 0 && ray->orig.x <= 0.2 && ray->orig.y >= 0 && ray->orig.y <= 0.2) 
	{
	//	ex = vec_new(0, 0, 10);
		printf("[CYLINDER]: cylinder point: x: %f, y: %f, z: %f,    ", ray->p.x, ray->p.y, ray->p.z); //erase
		printf("[CYLINDER]: winning point: x: %f, y: %f, z: %f,    ", ray->hit.p.x, ray->hit.p.y, ray->hit.p.z); //erase
		printf("distance to cylinder point: %f\n", dist(&ray->p, &ray->zero)); //erase
	}
//	printf("cylinder pointer %p, ray pointer %p, item pointer %p\n", obj, ray, item);
}

void	cy_get_norm(t_obj *cy, t_hit *hit)
{
	t_vec	mvec;
	t_point	a;

	hit->rgb = cy->cy->rgb;
	mvec = mult_new(&cy->cy->nov, cy->cy->m[0]);
	a = sum_vec(&cy->cy->pos, &mvec);
	hit->norm = substr_vec(&hit->p, &a);
	if (dot_prod(&hit->norm, &mvec) != 0)
	{
		mvec = mult_new(&cy->cy->nov, cy->cy->m[1]);
		a = sum_vec(&cy->cy->pos, &mvec);
		hit->norm = substr_vec(&hit->p, &a);
	}
	norm_vector(&hit->norm);
//	printf("cylinder pointer %p, ray pointer %p\n", cy, hit);
}