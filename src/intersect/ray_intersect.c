/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:39:31 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/23 12:58:59 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ray_init(t_ray *ray)
{
	ray->zero = vec_new(0, 0, 0);	//  point on the screen (most probably not needed in the struct)
	unit_vector(&ray->orig, &ray->norm);
//	ray->k1 = dot_prod(&ray->norm, &ray->norm); //??? but it's 1
	ray->k1 = 1;
	ray->dist = MAXFLOAT;
	ray->hit.obj = NULL;
	ray->hit.obst = false;
}

void	check_dist(t_point *p, t_ray *ray, t_item *obj, double dist)
{
	if (dist > ray->dist)
		return ;
	ray->dist = dist;
	ray->hit.p = *p;
	ray->hit.obj = obj;
	ray->hit.obst = true;
}

unsigned int	diffuse_light(t_light *light, t_hit *hit, unsigned int amb, float d_fact)
{
	unsigned int	d_color;

	if (d_fact > 0)
		d_color = color_x_fact(rgb_to_hex(light->rgb), light->b * d_fact);
	else
		d_color = 0;
	return (color_mult(rgb_to_hex(hit->rgb), add_color(amb, d_color)));
}

unsigned int	phong_light(t_light *light, t_hit *hit, float dot)
{
	t_vec			reflex;
	float			s_fact;
	unsigned int	specular;
	t_vec			cam_hit;

	reflex = mult_new(&hit->norm, 2 * dot);
	reflex = substr_vec(&reflex, &light->pos);
	unit_vector(&reflex, &reflex);
	unit_vector(&hit->p, &cam_hit);
	s_fact = pow(dot_prod(&reflex, &cam_hit), 500);
	specular = color_x_fact(rgb_to_hex(light->rgb), s_fact);
	return (specular);
}

void	obj_color(t_amb *amb, t_light light, unsigned int *color, t_hit *hit)
{
	unsigned int	ambient;
	unsigned int	diffuse;
	float			dot;

	light.pos = substr_vec(&light.pos, &hit->p);
	unit_vector(&light.pos, &light.pos);
	dot = dot_prod(&light.pos, &hit->norm);
	if (hit->type == pla && dot < 0)
	{
		hit->norm = opp_vec(&hit->norm);
		dot = -dot;
	}
	ambient = color_x_fact(color_mult(rgb_to_hex(light.rgb), \
			rgb_to_hex(hit->rgb)), amb->ratio);
	diffuse = diffuse_light(&light, hit, 
			color_x_fact(rgb_to_hex(amb->rgb), amb->ratio), dot);
	if (dot_prod(&light.pos, &hit->norm) > 0.2)
	{
		*color = add_color(diffuse, phong_light(&light, hit, dot));
	}
	else
		*color = diffuse;
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
	/*if (ray->dist < MAXFLOAT)
		sc->mlx.color = 0xff0000;
	else
		sc->mlx.color = 0;*/
	if (ray->dist < MAXFLOAT)
	{
		ray->hit.obj->get_norm(&ray->hit.obj->type, &ray->hit);
		obj_color(&sc->amb, sc->light, &sc->mlx.color, &ray->hit);
	}
	else
		sc->mlx.color = 0;
}
