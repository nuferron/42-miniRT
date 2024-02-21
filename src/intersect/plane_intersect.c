/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:28:21 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/19 19:21:22 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	pl_intersect(t_obj *obj, t_ray *ray, t_item *item)
{
	printf("plane pointer %p, ray pointer %p, item pointer %p\n", obj, ray, item);
}

void	pl_get_norm(t_obj *obj, t_hit *hit)
{
	printf("plane pointer %p, ray pointer %p\n", obj, hit);
}