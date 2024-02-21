/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:39:31 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/21 19:38:48 by nuferron         ###   ########.fr       */
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

/*void	ambient_lightning(t_sc *sc, int *hit_rgb, int *final)
{
	final[0] = sc->light.rgb[0];
	final[1] = sc->light.rgb[1];
	final[2] = sc->light.rgb[2];
	color_intensity(final, sc->amb.ratio);
	multiply_color(final, hit_rgb);
}*/

/*void	diffuse_lightning(t_sc *sc, t_hit *hit, int *final)
{
	float	k;
	int		diffuse[3];
	t_vec	l_ray;

	l_ray = substr_vec(&sc->light.pos, &hit->p);
	unit_vector(&l_ray, &l_ray);
	k = dot_prod(&l_ray, &hit->norm);
	if (k > 0)
	{
		diffuse[0] = sc->light.rgb[0];
		diffuse[1] = sc->light.rgb[1];
		diffuse[2] = sc->light.rgb[2];
		color_intensity(diffuse, sc->light.b * k);
	}
	else
	{
		diffuse[0] = 0;
		diffuse[1] = 0;
		diffuse[2] = 0;
	}
	add_color(final, diffuse);
	multiply_color(final, hit->rgb);
}*/

unsigned int	diffuse_light(t_light *light, t_hit *hit, unsigned int amb)
{
	float			d_fact;
	unsigned int	d_color;

	d_fact = dot_prod(&light->pos, &hit->norm);
	if (d_fact > 0)
	{
		d_color = color_x_fact(rgb_to_hex(light->rgb), light->b * d_fact);
	}
	else
		d_color = 0;
	return (color_mult(rgb_to_hex(hit->rgb), add_color(amb, d_color)));
}

/*void	phong_lightning(t_sc *sc, t_hit *hit, int *final)
{
	t_vec	reflected;
	t_vec	l_ray;
	int		specular[3];
	float	spec_fact;

	l_ray = substr_vec(&sc->light.pos, &hit->p);
	unit_vector(&l_ray, &l_ray);
	reflected = mult_new(&hit->norm, 2 * dot_prod(&hit->norm, &l_ray));
	reflected = mult_vec(&reflected, &l_ray);
	unit_vector(&reflected, &reflected);
	spec_fact = dot_prod(&reflected, &hit->norm);
	specular[0] = sc->light.rgb[0];
	specular[1] = sc->light.rgb[1];
	specular[2] = sc->light.rgb[2];
	color_intensity(specular, spec_fact);
	add_color(final, specular);
}*/

/*void	obj_color(t_sc *sc, unsigned int *color, t_hit *hit)
{
	int	final_color[3];

	light_hex = rgb_to_hex(sc->light.rgb);
	ambient_lightning(sc, hit->rgb, final_color);
	diffuse_lightning(sc, hit, final_color);
	//phong_lightning();
	*color = rgb_to_hex(final_color);
}*/

void	obj_color(t_sc *sc, unsigned int *color, t_hit *hit)
{
	unsigned int	ambient;
	unsigned int	diffuse;
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
	if (ray->dist < MAXFLOAT)
	{
		ray->hit.obj->get_norm(&ray->hit.obj->type, &ray->hit);
		obj_color(sc, &sc->mlx.color, &ray->hit);
	}
	else
		sc->mlx.color = color_x_fact(rgb_to_hex(sc->amb.rgb), sc->amb.ratio);
}
