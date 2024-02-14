/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:01:29 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/15 00:05:58 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

typedef struct s_vec t_vec;
typedef struct s_vec t_point;
typedef struct s_ray t_ray;
typedef struct s_sp t_sp;

/* plane_intersect.c - intersection with plane equations  **************/
void	pl_intersect(t_obj *obj, t_ray *ray);

/* sphere_intersect.c - intersection with sphere equations  **************/
void	sph_intersect(t_obj *obj, t_ray *ray);
void	sp_get_norm(t_sp *sp, t_ray *ray);

/* cylinder_intersect.c - intersection with cylinder equations  **************/
void	cy_intersect(t_obj *obj, t_ray *ray);

/* ray_intersect.c - dealing with ray variables  **************/
void	ray_init(t_ray *ray);
void	check_dist(t_point *p, t_ray *ray, double dist);
void	all_intersect(t_sc *sc, t_ray *ray);
void	memorize(t_obj *obj, t_ray *ray, int type);

#endif
