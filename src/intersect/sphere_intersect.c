/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:58:05 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/03/08 13:48:36 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	sph_intersect(t_obj *obj, t_ray *ray, t_item *item)
{
	t_vars	var;
	t_sp	*sp;

	sp = obj->sp;
	ray->hit.obst = false;
	var.oc = substr_vec(&ray->zero, &sp->pos);
	var.k1 = 1;
	var.k2 = 2 * dot_prod(&var.oc, &ray->norm);
	var.k3 = dot_prod(&var.oc, &var.oc) - sp->r * sp->r;
	if (!count_t(ray, &var))
		return ;
	if (ray->t[0] > 0)
	{
		ray->p = mult_new(&ray->norm, ray->t[0]);
		ray->p = sum_vec(&ray->zero, &ray->p);
		check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
	}
	if (var.discr && ray->t[1] > 0)
	{
		ray->p = mult_new(&ray->norm, ray->t[1]);
		ray->p = sum_vec(&ray->zero, &ray->p);
		check_dist(&ray->p, ray, item, dist(&ray->p, &ray->zero));
	}
	if (ray->hit.obst == true)
		ray->hit.type = sph;
}

void	sp_get_norm(t_obj *sp, t_hit *hit, t_ray *ray)
{
	(void)ray;
	hit->norm = substr_vec(&hit->p, &sp->sp->pos);
	norm_vector(&hit->norm);
	hit->rgb = sp->sp->rgb;
	hit->type = sph;
}

int	count_t(t_ray *ray, t_vars *var)
{
	var->discr = var->k2 * var->k2 - 4 * var->k1 * var->k3;
	if (var->discr < 0)
		return (0);
	var->discr = sqrt(var->discr);
	ray->t[0] = (-var->k2 + var->discr) / (2 * var->k1);
	if (var->discr)
		ray->t[1] = (-var->k2 - var->discr) / (2 * var->k1);
	else
		ray->t[1] = ray->t[0];
	return (1);
}
