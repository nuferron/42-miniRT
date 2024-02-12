/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:44:54 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/12 11:04:38 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* returns a vector which is a sum of vectors a and b */
t_vec	sum_vec(t_vec *a, t_vec *b)
{
	t_ve	res;

	res.x = a->x + b->x;
	res.y = a->y + b->y;
	res.z = a->z + b->z;
	return (res);
}

/* from - is the vector from which you are substructing
what - is a vector which you are substructing 
returns a resulting vector*/
t_vec	substr_vec(t_vec *from, t_vec *what)
{
	t_vec	res;

	res.x = from->x - what->x;
	res.y = from->y - what->y;
	res.z = from->z - what->z;
	return (res);
}

/* returns the distance from point p1 to point p2*/
double	dist(t_point *p1, t_point *p2)
{
	t_vec	temp;

	temp = substr_vec(p1, p2);
	return (vec_mod(&temp));
}
