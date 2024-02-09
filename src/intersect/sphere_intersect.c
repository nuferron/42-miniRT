/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:58:05 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/09 18:57:26 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	sph_intersect(t_sp *sp, t_ray *ray)
{
	t_vars	var;
	t_vec	v1;
	t_point	p1;
	t_point	p2;

	var.oc = substr_vec(&ray->ray_orig, &sp->pos);
	var.vo = substr_vec(&ray->ray_vec, &ray->ray_orig); // D probably add it to the ray struct?
	var.vo_dot = dot_prod(&var.vo, &var.vo); // k1 - probably add it to the ray struct?
	var.k2 = 2 * dot_prod(&var.oc, &var.vo);
	var.discr = var.k2 * var.k2 - 4 * var.vo_dot * (dot_prod(&var.oc, &var.oc) - sp->r * sp->r);
	if (var.discr < 0)
		return (-1); // no intersections
	else if (var.discr == 0)
		return (-var.k2 / (2 * var.vo_dot));	// here what we do if there is one point
	v1 = mult_new(&var.vo, (-var.k2 - var.discr) / (2 * var.vo_dot));  // - discr
	p1 = sum_vec(&ray->ray_orig, &v1); //first check the case if t < 0 (behind the camera)
	if (dist(&p1, &ray->ray_orig) < ray->dist)
		ray->dist = dist(&p1, &ray->ray_orig);
		//save the point in the ray->hit
	mult_fac(&var.vo, (-var.k2 + var.discr) / (2 * var.vo_dot));  // + discr
	p2 = sum_vec(&ray->ray_orig, &var.vo); 
	if (dist(&p2, &ray->ray_orig) < ray->dist)
		ray->dist = dist(&p2, &ray->ray_orig);
	// how to save the intersection point?
	return (1);
}
