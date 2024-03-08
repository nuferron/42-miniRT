/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:28:24 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/03/08 13:47:06 by nzhuzhle         ###   ########.fr       */
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
	var.k2 = 2 * (dot_prod(&ray->norm, &var.oc) - \
	(1 + co->tg * co->tg) * dn * posn);
	var.k3 = dot_prod(&var.oc, &var.oc) - (1 + co->tg * co->tg) * posn * posn;
	cone_check_disk(ray, co, item, &dn);
	if (!count_t(ray, &var))
		return ;
	co->m[0] = (ray->t[0] * dn + posn);
	co->m[1] = (ray->t[1] * dn + posn);
	cone_check_body(ray, item, co);
}

void	cone_check_body(t_ray *ray, t_item *item, t_co *co)
{
	bool	temp;

	temp = ray->hit.obst;
	ray->hit.obst = false;
	if (ray->t[0] > 0 && co->m[0] < co->h && co->m[0] > 0)
	{
		ray->p = mult_new(&ray->norm, ray->t[0]);
		ray->p = sum_vec(&ray->zero, &ray->p);
		check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
	}
	if (ray->t[1] > 0 && co->m[1] < co->h && co->m[1] > 0 && \
	ray->t[0] != ray->t[1])
	{
		ray->p = mult_new(&ray->norm, ray->t[1]);
		ray->p = sum_vec(&ray->zero, &ray->p);
		check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
	}
	if (ray->hit.obst == true)
		ray->hit.type = cone;
	if (temp == true)
		ray->hit.obst = true;
}

void	cone_check_disk(t_ray *ray, t_co *co, t_item *item, double *dn)
{
	double	d;

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
}
