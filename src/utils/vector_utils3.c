/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:12:15 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/05 17:20:02 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* returns a vector which is the product of the vector v and 
a number "factor" */
t_vec	mult_new(t_vec *v, double factor)
{
	t_vec	res;

	res.x = v->x * factor;
	res.y = v->y * factor;
	res.z = v->z * factor;
	return (res);
}

/* multiplies the same vector v by a number "factor" */
void	mult_fac(t_vec *v, double factor)
{
	v->x *= factor;
	v->y *= factor;
	v->z *= factor;
}

/* returns a vector which is a resust of division of the vector v by 
a number "factor" */
t_vec	div_new(t_vec *v, double factor)
{
	t_vec	res;

	res.x = v->x / factor;
	res.y = v->y / factor;
	res.z = v->z / factor;
	return (res);
}

/* divides the vector v by a number "factor" */
void	div_fac(t_vec *v, double factor)
{
	v->x /= factor;
	v->y /= factor;
	v->z /= factor;
}