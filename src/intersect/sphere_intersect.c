/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:58:05 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/12 21:09:39 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Probably there is no need to return anything */
void	sph_intersect(t_sp *sp, t_ray *ray)
{
	t_vars	var;
	t_point	p;

	var.oc = substr_vec(&ray->zero, &sp->pos);
	var.k2 = 2 * dot_prod(&var.oc, &ray->norm);
	var.discr = var.k2 * var.k2 - 4 * ray->k1 * (dot_prod(&var.oc, &var.oc) - sp->r * sp->r);
	if (var.discr < 0)
		return ; // no intersections
	var.t = (-var.k2 + var.discr) / (2 * ray->k1);
	if (var.t > 0) // what do we do if the intrsection is in the zero point???
	{
		p = mult_new(&ray->norm, var.t);
		check_dist(&p, ray, dist(&p, &ray->zero));
	}
	if (!var.discr)
		return ;
	var.t = (-var.k2 - var.discr) / (2 * ray->k1);
	if (var.t <= 0)
		return ;
	p = mult_new(&ray->norm, var.t);
	check_dist(&p, ray, dist(&p, &ray->zero));
}
