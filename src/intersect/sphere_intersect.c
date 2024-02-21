/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:58:05 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/21 19:40:34 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Probably there is no need to return anything */
void	sph_intersect(t_obj *obj, t_ray *ray, t_item *item)
{
	t_vars	var;
//	t_point	p;
	t_sp	*sp;
//	t_point ex;

	sp = obj->sp;
//	ray->hit.rec = false;
	var.oc = substr_vec(&ray->zero, &sp->pos);
	var.k2 = 2 * dot_prod(&var.oc, &ray->norm);
	var.discr = var.k2 * var.k2 - 4 * ray->k1 * (dot_prod(&var.oc, &var.oc) - sp->r * sp->r);
	if (var.discr < 0)
		return ; // no intersections
	var.discr = sqrt(var.discr);
	ray->t = (-var.k2 + var.discr) / (2 * ray->k1);
	if (ray->t > 0) // what do we do if the intrsection is in the zero point???
	{
		ray->p = mult_new(&ray->norm, ray->t);
		check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
	}
	ray->t = (-var.k2 - var.discr) / (2 * ray->k1);
	if (var.discr && ray->t > 0)
	{
		ray->p = mult_new(&ray->norm, ray->t);
		check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
	}
/*	if (ray->orig.x >= 0 && ray->orig.x <= 0.2 && ray->orig.y >= 0 && ray->orig.y <= 0.2) 
	{
		ex = vec_new(0, 0, 10);
		printf("center x: %f, y: %f, z: %f\n", ray->hit.p.x, ray->hit.p.y, ray->hit.p.z); //erase
		printf("distance from center: %f, t: %f, right dist: %f \n", dist(&p, &sp->pos), var.t, dist(&ex, &sp->pos)); //erase
	}*/
}

void	sp_get_norm(t_obj *sp, t_hit *hit)
{
	hit->norm = substr_vec(&hit->p, &sp->sp->pos);
	norm_vector(&hit->norm);
	hit->rgb = sp->sp->rgb;
//	printf("r: %i, g: %i\n", hit->rgb[0], hit->rgb[1]);
}
