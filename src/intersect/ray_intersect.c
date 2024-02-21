/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:39:31 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/21 21:05:53 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ray_init(t_ray *ray)
{
	ray->zero = vec_new(0, 0, 0);	//  point on the screen (most probably not needed in the struct)
	unit_vector(&ray->orig, &ray->norm);
	ray->k1 = dot_prod(&ray->norm, &ray->norm);
	ray->dist = MAXFLOAT;
	ray->hit.obj = NULL;
	ray->hit.type = 0;
//	ray->hit.rec = false;
}

void	check_dist(t_point *p, t_ray *ray, t_item *obj, double dist)
{
	if (dist > ray->dist)
		return ;
	ray->dist = dist;
	ray->hit.p = *p;
	ray->hit.obj = obj;
//	ray->hit.rec = true;
}

unsigned int	diffuse_light(t_light *light, t_hit *hit, unsigned int amb)
{
	float			d_fact;
	unsigned int	d_color;

	d_fact = dot_prod(&light->pos, &hit->norm);
	if (d_fact > 0)
		d_color = color_x_fact(rgb_to_hex(light->rgb), light->b * d_fact);
	else
		d_color = 0;
	return (color_mult(rgb_to_hex(hit->rgb), add_color(amb, d_color)));
}

unsigned int	phong_light(t_light *light, t_hit *hit)
{
	t_vec			reflex;
	float			s_fact;
	unsigned int	specular;
	t_vec			cam_hit;
	if (dot_prod(&light->pos, &hit->norm) <= 0)
		return (0);
	reflex = mult_new(&hit->norm, 2 * dot_prod(&hit->norm, &light->pos));
	reflex = substr_vec(&reflex, &light->pos);
	unit_vector(&reflex, &reflex);
	unit_vector(&hit->p, &cam_hit);
	s_fact = pow(dot_prod(&reflex, &cam_hit), 100);
	specular = 0;
	if (s_fact > 0 && s_fact <= 1)
		specular = color_x_fact(rgb_to_hex(light->rgb), s_fact);
	return (specular);
}

void	obj_color(t_sc *sc, unsigned int *color, t_hit *hit)
{
	unsigned int	ambient;
	unsigned int	diffuse;
	unsigned int	specular;
	t_light			l_cpy;

	l_cpy.pos = substr_vec(&sc->light.pos, &hit->p);
	unit_vector(&l_cpy.pos, &l_cpy.pos);
	l_cpy.b = sc->light.b;
	l_cpy.rgb[0] = sc->light.rgb[0];
	l_cpy.rgb[1] = sc->light.rgb[1];
	l_cpy.rgb[2] = sc->light.rgb[2];
	ambient = color_x_fact(color_mult(rgb_to_hex(sc->light.rgb), \
			rgb_to_hex(hit->rgb)), sc->amb.ratio);
	diffuse = diffuse_light(&l_cpy, hit,
	color_x_fact(rgb_to_hex(sc->amb.rgb), sc->amb.ratio));
	specular = phong_light(&l_cpy, hit);
	*color = add_color(diffuse, specular);
}

void	all_intersect(t_sc *sc, t_ray *ray)
{
	t_item	*obj;

	obj = sc->objs;
	while (obj)
	{
		obj->intersect(&obj->type, ray, obj);
		obj = obj -> next;
	}
	if (ray->dist < MAXFLOAT)
	{
		ray->hit.obj->get_norm(&ray->hit.obj->type, &ray->hit);
		obj_color(sc, &sc->mlx.color, &ray->hit);
	}
	else
		sc->mlx.color = 0;
}
