/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:01:29 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/27 18:17:36 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

typedef struct s_vec t_vec;
typedef struct s_vec t_point;
typedef struct s_ray t_ray;
typedef struct s_sp t_sp;

/* plane_intersect.c - intersection with plane equations  **************/
void	pl_intersect(t_obj *obj, t_ray *ray, t_item *item);
void	pl_get_norm(t_obj *obj, t_hit *hit);

/* sphere_intersect.c - intersection with sphere equations  **************/
void	sph_intersect(t_obj *obj, t_ray *ray, t_item *item);
void	sp_get_norm(t_obj *sp, t_hit *hit);
int		count_t(t_ray *ray, t_vars *var);

/* cylinder_intersect.c - intersection with cylinder equations  **************/
void	cy_intersect(t_obj *obj, t_ray *ray, t_item *item);
int		cy_check_body(t_ray *ray, t_item *item, t_cy *cy);
void	cy_check_disk(t_ray *ray, t_cy *cy, t_item *item, float *dn);
void	cy_get_norm(t_obj *obj, t_hit *hit);

/* ray_intersect.c - dealing with ray variables  **************/
void	ray_init(t_ray *ray);
void	check_dist(t_point *p, t_ray *ray, t_item *item, double dist);
void	all_intersect(t_sc *sc, t_ray *ray);
//void	memorize(t_obj *obj, t_ray *ray, int type);

#endif
