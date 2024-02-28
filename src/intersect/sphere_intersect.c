/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:58:05 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/28 16:54:50 by nzhuzhle         ###   ########.fr       */
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
//	printf("[SPHERE]: entered\n");
//	ray->hit.rec = false;
	ray->hit.obst = false;
	var.oc = substr_vec(&ray->zero, &sp->pos);
	var.k1 = 1;
	var.k2 = 2 * dot_prod(&var.oc, &ray->norm);
	var.k3 = dot_prod(&var.oc, &var.oc) - sp->r * sp->r;
//	var.discr = var.k2 * var.k2 - 4 * var.k1 * var.k3;
	if (!count_t(ray, &var))
		return ; // no intersections
//	var.discr = sqrt(var.discr);
//	ray->t[0] = (-var.k2 + var.discr) / (2 * var.k1);
	if (ray->t[0] > 0) // what do we do if the intrsection is in the zero point???
	{
		ray->p = mult_new(&ray->norm, ray->t[0]);
		ray->p = sum_vec(&ray->zero, &ray->p);
		check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
	}
//	ray->t[1] = (-var.k2 - var.discr) / (2 * var.k1);
	if (var.discr && ray->t[1] > 0)
	{
		ray->p = mult_new(&ray->norm, ray->t[1]);
		check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
	}
	if (ray->hit.obst == true)
		ray->hit.type = sph;
//	printf("[SPHERE]: leaving\n");
	/*if (ray->orig.x >= 0 && ray->orig.x <= 0.2 && ray->orig.y >= 0 && ray->orig.y <= 0.2) 
	{
	//	ex = vec_new(0, 0, 10);
		printf("[SPHERE]: winning point: x: %f, y: %f, z: %f,    ", ray->hit.p.x, ray->hit.p.y, ray->hit.p.z); //erase
		printf("distance to this point: %f\n", dist(&ray->p, &ray->zero)); //erase
	}*/
}

void	sp_get_norm(t_obj *sp, t_hit *hit)
{
	hit->norm = substr_vec(&hit->p, &sp->sp->pos);
	norm_vector(&hit->norm);
	hit->rgb = sp->sp->rgb;
	hit->type = sph;
//	printf("r: %i, g: %i\n", hit->rgb[0], hit->rgb[1]);
}

int	count_t(t_ray *ray, t_vars *var)
{
	var->discr = var->k2 * var->k2 - 4 * var->k1 * var->k3;
	//	printf("discr: %f\n", var->discr);
	if (var->discr < 0)
		return (0); // no intersections
	var->discr = sqrt(var->discr);
	ray->t[0] = (-var->k2 + var->discr) / (2 * var->k1);
	if (var->discr)
		ray->t[1] = (-var->k2 - var->discr) / (2 * var->k1);
	else
		ray->t[1] = ray->t[0];
	return (1);
}