/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:01:29 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/03/05 18:00:59 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

#include "items.h"

typedef struct s_light t_light;
typedef struct s_vec t_vec;
typedef struct s_vec t_point;
typedef struct s_ray t_ray;
typedef struct s_sp t_sp;

enum	e_type
{
	sph = 0,
	pla = 1,
	cyl = 2,
	disk = 3,
	cone = 4
};

/* A variable structure for sphere intersection */
typedef struct s_vars
{
	t_vec	oc;		//	ray origin - shape center
	double	k1;
	double	k2;		//	2 * dot product (oc, vo)
	double	k3;
	double	discr;	//	discriminant
}	t_vars;

typedef struct s_hit
{
	t_point		p;		// the minimal point of intersection
	t_vec		norm;	// normalized vector of the hit
	t_item		*obj;	// pointer to the winner object
	int			*rgb;
	bool		obst; 	// obstices 0 if there is access to light
	enum e_type	type;
}	t_hit;

typedef struct s_ray
{
	t_hit	hit;	// info about the record hit
	t_point	zero;	// the coordinates of the camera
	t_vec	norm;	// the normalized ray vector
	t_point	orig;	// point on the screen
	t_point	p;		// variable - intersection point
	double	t[2];	// variable - distance coefficient to the intersection point
	double	dist;	// the minimal distance
}	t_ray;

/* plane_intersect.c - intersection with plane equations  **************/
void	pl_intersect(t_obj *obj, t_ray *ray, t_item *item);
void	pl_get_norm(t_obj *obj, t_hit *hit, t_ray *ray);

/* sphere_intersect.c - intersection with sphere equations  **************/
void	sph_intersect(t_obj *obj, t_ray *ray, t_item *item);
void	sp_get_norm(t_obj *sp, t_hit *hit, t_ray *ray);
int		count_t(t_ray *ray, t_vars *var);

/* cylinder_intersect.c - intersection with cylinder equations  **************/
void	cy_intersect(t_obj *obj, t_ray *ray, t_item *item);
void	cy_check_body(t_ray *ray, t_item *item, t_cy *cy);
void	cy_check_disk(t_ray *ray, t_cy *cy, t_item *item, float *dn);
void	cy_get_norm(t_obj *obj, t_hit *hit, t_ray *ray);

/* cone_intersect.c - intersection with cone equations  **************/
void	cone_intersect(t_obj *obj, t_ray *ray, t_item *item);
void	cone_check_body(t_ray *ray, t_item *item, t_co *co);
void	cone_check_disk(t_ray *ray, t_co *co, t_item *item, float *dn);
void	cone_get_norm(t_obj *obj, t_hit *hit, t_ray *ray);

/* ray_intersect.c - dealing with ray variables  **************/
void	ray_init(t_ray *ray);
void	check_dist(t_point *p, t_ray *ray, t_item *item, double dist);
void	all_intersect(t_sc *sc, t_ray *ray);
void	init_light_ray(t_ray *ray, t_light *l, t_hit *hit);

#endif
