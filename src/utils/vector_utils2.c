/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:44:54 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/04 22:40:07 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec	sum_vec(t_vec a, t_vec b)
{
	t_vec res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}
/* from - is the vector from which you are substructing
what - is a vector which you are substructing */
t_vec	substr_vec(t_vec from, t_vec what)
{
	t_vec res;

	res.x = from.x - what.x;
	res.y = from.y - what.y;
	res.z = from.z - what.z;
	return (res);
}

t_vec	mult_fac(t_vec v, double factor)
{
	t_vec	res;

	res.x = v.x * factor;
	res.y = v.y * factor;
	res.z = v.z * factor;
	return (res);
}

t_vec	div_fac(t_vec v, double factor)
{
	t_vec	res;

	res.x = v.x / factor;
	res.y = v.y / factor;
	res.z = v.z / factor;
	return (res);
}

double	dist(t_vec point1, t_vec point2)
{
	return (vec_mod(substr_vec(point1, point2)));
}