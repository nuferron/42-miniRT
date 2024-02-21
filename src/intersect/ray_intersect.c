/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:39:31 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/21 11:00:02 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ray_init(t_ray *ray)
{
	ray->zero = vec_new(0, 0, 0);	//  point on the screen (most probably not needed in the struct)
	unit_vector(&ray->orig, &ray->norm);
	/*if (ray->orig.x >= 0 && ray->orig.x <= 0.2 && ray->orig.y >= 0 && ray->orig.y <= 0.2)
		printf("ray normalized: %f, y: %f, z: %f\n", ray->norm.x, ray->norm.y, ray->norm.z); //erase
	*/
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

void	memorize(t_obj *obj, t_ray *ray, int type)
{
		ray->hit.obj = obj;
		ray->hit.type = type;
		ray->hit.rec = false;
}

	/*if (ray->hit.p.x >= -0.9 && ray->hit.p.x <= 0.1
		&& ray->hit.p.y >= -0.9 && ray->hit.p.y <= 0.1
		&& ray->hit.p.z >= 13.99 && ray->hit.p.z <= 14.01)
		printf("hit x %f, y %f, z %f\n", ray->hit.p.x, ray->hit.p.y, ray->hit.p.z);*/

/*void	obj_color(t_sc *sc, t_hit *hit, unsigned int *color, int *tmp)
{
	double	dot;
	t_vec	light_ray;
	int		rgb[3];

	(void)tmp;
	light_ray = substr_vec(&sc->light.pos, &hit->p);
	unit_vector(&light_ray, &light_ray);
	dot = dot_prod(&light_ray, &hit->norm);
	//color_intensity(sc->amb.rgb, sc->amb.ratio);
	if (dot <= 0)
	{
		rgb[0] = sc->amb.rgb[0];
		rgb[1] = sc->amb.rgb[1];
		rgb[2] = sc->amb.rgb[2];
		// *color = rgb_to_hex(sc->amb.rgb[0], sc->amb.rgb[1], sc->amb.rgb[2]);
		//printf("hit x %f, y %f, z %f\t", hit->p.x, hit->p.y, hit->p.z);
		//printf("dot: %f\n", dot);
		// *color = 0;
	}
	else
	{
		*color = 0x00ff00;
		rgb[0] = tmp[0];
		rgb[1] = tmp[1];
		rgb[2] = tmp[2];
		// *color = 0;
	}
	color_intensity(rgb, sc->light.b);
	add_color(rgb, sc->amb.rgb);
	multiply_color(rgb, sc->light.rgb);
	*color = rgb_to_hex(rgb[0], rgb[1], rgb[2]);
}*/

/*void	obj_color(t_sc *sc, t_hit *hit, unsigned int *color, int *tmp)
{
	t_vec	l_ray;
	double	dot;
	float	l_mod2;
	float	col_bright;
	
	(void)tmp;
	l_ray = substr_vec(&sc->light.pos, &hit->p);
	unit_vector(&l_ray, &l_ray);
	l_mod2 = l_ray.x * l_ray.x + l_ray.y * l_ray.y + l_ray.z * l_ray.z;
	dot = dot_prod(&l_ray, &hit->norm);
	if (dot <= 0)
		col_bright = 0;
	else
		col_bright = (sc->light.b * dot * 500) / (4 * M_PI * l_mod2);
	color_intensity(tmp, col_bright);
	add_color(tmp, sc->amb.rgb);
	multiply_color(tmp, sc->light.rgb);
	*color = rgb_to_hex(tmp);
}*/
void	ambient_lightning(t_sc *sc, int *tmp, unsigned int *color)
{
	int	rgb[3];

	rgb[0] = sc->light.rgb[0];
	rgb[1] = sc->light.rgb[1];
	rgb[2] = sc->light.rgb[2];
	color_intensity(rgb, sc->amb.ratio);
	multiply_color(rgb, tmp);
	*color = rgb_to_hex(rgb);
}

void	diffuse_lightning(t_sc *sc, t_hit *hit, int *tmp, unsigned int *color)
{
	float	k;
	t_vec	l_ray;

	l_ray = substr_vec(&sc->light.pos, &hit->p);
	unit_vector(&l_ray, &l_ray);
	k = dot_prod(&l_ray, &hit_norm);
}

void	obj_color(t_sc *sc, unsigned int *color, int *tmp)
{
	ambient_lightning(sc, tmp, color);
}

void	all_intersect(t_sc *sc, t_ray *ray)
{
	t_item	*obj;

	obj = sc->objs;
	while (obj)
	{
		obj->intersect(&obj->type, ray);
		obj = obj->next;
	}
	if (ray->dist < MAXFLOAT)
	{
		ray->hit.obj->get_norm(&ray->hit.obj->type, &ray->hit);
		sc->mlx.color = 0x00FF00;
		int tmp[3];
		tmp[0] = 0;
		tmp[1] = 255;
		tmp[2] = 0;
		obj_color(sc, &sc->mlx.color, tmp);
	}
	else
		sc->mlx.color = 0x0000FF;
}
