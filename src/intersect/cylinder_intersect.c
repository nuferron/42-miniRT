/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 21:53:10 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/19 19:21:00 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	cy_intersect(t_obj *obj, t_ray *ray, t_item *item)
{
	printf("cylinder pointer %p, ray pointer %p, item pointer %p\n", obj, ray, item);
}

void	cy_get_norm(t_obj *obj, t_hit *hit)
{
	printf("cylinder pointer %p, ray pointer %p\n", obj, hit);
}