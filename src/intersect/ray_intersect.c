/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:39:31 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/21 12:46:40 by nuferron         ###   ########.fr       */
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
void	ambient_lightning(t_sc *sc, int *hit_rgb, int *final)
{
	final[0] = sc->light.rgb[0];
	final[1] = sc->light.rgb[1];
	final[2] = sc->light.rgb[2];
	color_intensity(final, sc->amb.ratio);
	multiply_color(final, hit_rgb);
}

void	diffuse_lightning(t_sc *sc, t_hit *hit, int *final)
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
}

/*void	phong_lightning(t_sc *sc, t_hit *hit, int *final)
{

}*/

void	obj_color(t_sc *sc, unsigned int *color, t_hit *hit)
{
	int	final_color[3];

	ambient_lightning(sc, hit->rgb, final_color);
	diffuse_lightning(sc, hit, final_color);
	*color = rgb_to_hex(final_color);
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
		sc->mlx.color = 0x00FF00;
		obj_color(sc, &sc->mlx.color, &ray->hit);
	}
	else
	{
		int	tmp[3];

		tmp[0] = sc->amb.rgb[0];
		tmp[1] = sc->amb.rgb[1];
		tmp[2] = sc->amb.rgb[2];
		color_intensity(tmp, sc->amb.ratio);
		sc->mlx.color = rgb_to_hex(tmp);
	}
}
