/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:39:31 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/12 13:44:29 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	ray_init(t_ray *ray)
{
	ray->zero = vec_new(0, 0, 0);	//  point on the screen (most probably not needed in the struct)
	unit_vector(&ray->orig, &ray->norm);
	ray->k1 = dot_prod(&ray->norm, &ray->norm);
	ray->dist = MAXFLOAT;
}

void	check_dist(t_point *p, t_ray *ray, double dist)
{
	if (dist > ray->dist)
		return ;
	ray->dist = dist;
	ray->hit = *p;
}

/*unsigned int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
*/
unsigned int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	obj_color(t_sc *sc, int *color, t_vec *light, t_vec *norm)
{
	double	dot;

	dot = dot_prod(light, norm);
	if (dot <= 0)
		*color = 0x000000;
	else
		*color = *color + (sc->light.b * dot * sc->amb.ratio);
}

void	all_intersect(t_sc *sc, t_ray *ray)
{
	sph_intersect(&sc->sp.obj[0], ray);
	t_sp	*sp = &sc->sp.obj[0];
	sc->mlx.color = create_rgb(sp->rgb[0], sp->rgb[1], sp->rgb[2]);
	if (ray->dist < MAXFLOAT)
		obj_color(sc, &sc->mlx.color, &ray->orig, &ray->norm);
	else
		sc->mlx.color = 0x000000;
}
