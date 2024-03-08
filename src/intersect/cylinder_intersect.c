/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:53:10 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/03/08 12:41:07 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	cy_intersect(t_obj *obj, t_ray *ray, t_item *item)
{
	t_vars	var;
	t_cy	*cy;
	double	dn;
	double	posn;

	cy = obj->cy;
	if (cy->r < 0.0000001)
		return ;
	var.oc = substr_vec(&ray->zero, &cy->pos);
	dn = dot_prod(&cy->nov, &ray->norm);
	var.k1 = 1 - dn * dn;
	posn = dot_prod(&cy->nov, &var.oc);
	var.k2 = 2 * (dot_prod(&ray->norm, &var.oc) - dn * posn);
	var.k3 = dot_prod(&var.oc, &var.oc) - posn * posn - cy->r * cy->r;
	cy_check_disk(ray, cy, item, &dn);
	if (!count_t(ray, &var))
		return ;
	cy->m[0] = (ray->t[0] * dn + posn);
	cy->m[1] = (ray->t[1] * dn + posn);
	cy_check_body(ray, item, cy);
}

void	cy_check_body(t_ray *ray, t_item *item, t_cy *cy)
{
	bool	temp;

	temp = ray->hit.obst;
	ray->hit.obst = false;
	if (ray->t[0] > 0 && cy->m[0] < cy->h && cy->m[0] > 0)
	{
		ray->p = mult_new(&ray->norm, ray->t[0]);
		ray->p = sum_vec(&ray->zero, &ray->p);
		check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
	}
	if (ray->t[1] > 0 && cy->m[1] < cy->h && cy->m[1] > 0)
	{
		ray->p = mult_new(&ray->norm, ray->t[1]);
		ray->p = sum_vec(&ray->zero, &ray->p);
		check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
	}
	if (ray->hit.obst == true)
		ray->hit.type = cyl;
	else if (temp == true)
		ray->hit.obst = true;
}

void	cy_check_disk(t_ray *ray, t_cy *cy, t_item *item, double *dn)
{
	double	d;

	ray->hit.obst = false;
	ray->t[0] = (cy->prod[0] - dot_prod(&ray->zero, &cy->nov)) / *dn;
	ray->t[1] = (cy->prod[1] - dot_prod(&ray->zero, &cy->nov)) / *dn;
	if (ray->t[0] > 0)
	{
		ray->p = mult_new(&ray->norm, ray->t[0]);
		ray->p = sum_vec(&ray->zero, &ray->p);
		d = dist(&cy->pos, &ray->p);
		if (d <= cy->r)
			check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
	}
	if (ray->t[1] > 0)
	{
		ray->p = mult_new(&ray->norm, ray->t[1]);
		ray->p = sum_vec(&ray->zero, &ray->p);
		d = dist(&cy->lim, &ray->p);
		if (d <= cy->r)
			check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
	}
	if (ray->hit.obst == true)
		ray->hit.type = disk;
}

void	cy_get_norm(t_obj *cy, t_hit *hit, t_ray *ray)
{
	t_vec	mvec;
	t_point	a;

	hit->rgb = cy->cy->rgb;
	if (hit->type == disk)
	{
		hit->norm = cy->cy->nov;
		if (dot_prod(&ray->norm, &hit->norm) > 0)
			mult_fac(&hit->norm, -1);
		return ;
	}
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
}
