/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:46:53 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/07 22:55:29 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	vec_new(double x, double y, double z)
{
	t_vec	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

double	dot_prod(t_vec *a, t_vec *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_vec	cross_prod(t_vec *v1, t_vec *v2)
{
	t_vec	res;

	res.x = v1->y * v2->z - v1->z * v2->y;
	res.y = v1->z * v2->x - v1->x * v2->z;
	res.z = v1->x * v2->y - v1->y * v2->x;
	return (res);
}

/* The length of the vector */
double	vec_mod(t_vec *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

/* saves in the t_vec n the normalized t_vec v */
void	unit_vector(t_vec *v, t_vec *n)
{
	double	mod;

	mod = vec_mod(v);
	n->x = v->x / mod;
	n->y = v->y / mod;
	n->z = v->z / mod;
}
/*
int main()
{
	t_vec	a;
	t_vec	b;

	a.x = 0;
	a.y = 0;
	a.z = 0;
	b.x = 10;
	b.y = 30;
	b.z = 50;
	t_vec	unit;
	unit.x = 0.169;
	unit.y = 0.507;
	unit.z = 0.845;
	unit_vector(&b, &unit);
	double dotp = dot_product(&unit, &unit);
	printf("%f\n", dotp);
	printf("expn %f\n", exp_n(2, -5));
	printf("main: %f\n", 0.028571 + 0.25143 + 0.714286);
}*/
