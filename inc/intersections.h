/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:01:29 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/11 18:46:18 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

typedef struct s_vec t_vec;
typedef struct s_vec t_point;
typedef struct s_ray t_ray;
typedef struct s_sp t_sp;

/* plane_intersect.c - intersection with plane equations  **************/

/* sphere_intersect.c - intersection with plane equations  **************/
void	sph_intersect(t_sp *sp, t_ray *ray);


/* ray_intersect.c - dealing with ray variables  **************/
t_ray	ray_init(t_point *orig);
void	check_dist(t_point *p, t_ray *ray, double dist);

#endif