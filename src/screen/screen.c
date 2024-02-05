/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 20:43:51 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/05 17:54:45 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdbool.h>
/*
int	inter_square(t_vec *ray)
{
	double	x, y = 0;
	double	lambda = 50 / ray->z;

	x = ray->x * lambda;
	y = ray->y * lambda;
	if (x > 400 && x < 600 && y > 400 && y < 600)
		return (1);
	return (0);
}
*/

double	screen_width(double fov)
{
	return (sin(fov * M_PI / 360) * 2 * FOCAL);
}

double	pixel_ratio(double screen)
{
	return (screen / WIDTH);
}

double	scalar_prod(t_vec *v, t_vec *w)
{
	return (v->x * w->x + v->y * w->y + v->z * w->z);
}

double	get_c_parabola(t_vec *v, float *p, double *d)
{
	double	z_sqd;
	double	vy_p;

	z_sqd = v->z * v->z;
	vy_p = v->y * *p;
	return (vy_p * vy_p + 2 * vy_p * z_sqd + z_sqd * z_sqd);
}

float get_vec_plane(t_vec *n, float *p, double *d)
{
	double	a;
	double	b;
	double	disc;

	a = n->x * n->x + n->y * n->y;
	b = -2 * n->y - 2 * *p * n->x * n->x;
	disc = b * b - 4 * a * get_c_parabola(n, p, d);
	if (disc < 0)
		return (-1);
	return ((float)(-b - sqrt(disc)) / (2 * a));
}

int main()
{
	t_vec	n;

	n.x = 3;
	n.y = 2;
	n.z = 1;
	double d = 150;
	float	p = 25.4;
	printf("c parabola: %f\n", get_c_parabola(&n, &n.y, &d));
	printf("c gwv: %f\n", get_vec_plane(&n, &p, &d));
}
