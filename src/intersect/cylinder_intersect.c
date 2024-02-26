/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:53:10 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/26 20:35:52 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	cy_intersect(t_obj *obj, t_ray *ray, t_item *item)
{
	t_vars	var;
	t_cy	*cy;
	float	dn;
	float	posn;

	cy = obj->cy;
//	printf("[CYLINDER]: entered\n");
	var.oc = substr_vec(&ray->zero, &cy->pos);
	dn = dot_prod(&cy->nov, &ray->norm);
	ray->k1 = 1 - dn * dn;
	posn = dot_prod(&cy->nov, &var.oc);
	var.k2 = 2 * (dot_prod(&ray->norm, &var.oc) - dn * posn);
	var.k3 = dot_prod(&cy->pos, &cy->pos) - posn * posn - cy->r * cy->r;
	count_t(ray, &var);
	printf("discr: %f\n", var.discr);
	if (var.discr < 0)
		return ;
	exit(1);
	cy->m[0] = (ray->t[0] * dn + posn);
	cy->m[1] = (ray->t[1] * dn + posn);
	cy_check_body(ray, item, cy);
//	printf("[CYLINDER]: LEAVING\n");
/*	if (cy_check_body(ray, item, cy) < 2 && cy_count_disk(ray, cy, &var))
		cy_check_disk(ray, item, cy);*/
	/*if (ray->orig.x >= 0 && ray->orig.x <= 0.2 && ray->orig.y >= 0 && ray->orig.y <= 0.2) 
	{
	//	ex = vec_new(0, 0, 10);
		printf("[CYLINDER]: cylinder point: x: %f, y: %f, z: %f,    ", ray->p.x, ray->p.y, ray->p.z); //erase
		printf("[CYLINDER]: winning point: x: %f, y: %f, z: %f,    ", ray->hit.p.x, ray->hit.p.y, ray->hit.p.z); //erase
		printf("distance to cylinder point: %f\n", dist(&ray->p, &ray->zero)); //erase
	}*/
//	printf("cylinder pointer %p, ray pointer %p, item pointer %p\n", obj, ray, item);
}

int	cy_check_body(t_ray *ray, t_item *item, t_cy *cy)
{
	int	res;

	res = 0;
	if (ray->t[0] > 0 && cy->m[0] < cy->h && cy->m[0] > 0) // what do we do if the intrsection is in the zero point???
	{
		res++;
		ray->p = mult_new(&ray->norm, ray->t[0]);
		check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
	}
	if (ray->t[0] == ray->t[1])
		return (res);
	else if (ray->t[1] > 0 && cy->m[1] < cy->h  && cy->m[1] > 0)
	{
		res++;
		ray->p = mult_new(&ray->norm, ray->t[1]);
		check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
	}
	return (res);
}

/*bool	cy_count_disk(t_ray *ray, t_cy *cy, t_vars *var)
{
	ray->hit.obst = false;
	disk_create_check(ray, cy, 0);
}*/


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