/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:11:28 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/19 17:33:23 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	exp_2(double b)
{
	return (b * b);
}

double	exp_n(double b, int n)
{
	int		i;
	double	r;
	int		neg;

	i = 1;
	r = b;
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	if (n == 0)
		return (0);
	while (i++ < n)
		r *= b;
	if (neg)
		return (1 / r);
	return (r);
}
