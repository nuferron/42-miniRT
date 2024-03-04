/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:59:25 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/04 16:08:47 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <math.h>
#include <fcntl.h>
#include <stdbool.h>

#include "errors.h"
#include "structures.h"
#include "operations.h"
#include "intersections.h"
#include "mlx_rt.h"
#include "libft/inc/libft.h"
#include "ft_dprintf/inc/libftprintf.h"

/* GETTING DATA */
int		check_input(int argc, char **argv, t_sc *sc);
void	coord_transformation(t_sc *sc);

/* MEMORY UTILS */
void	sp_free(t_obj *obj);
void	pl_free(t_obj *obj);
void	cy_free(t_obj *obj);
void	cone_free(t_obj *obj);

/* UTILS */
int		is_float(char *str); //not in utils
void	skip_space(char *line, int *i);
void	skip_number(char *line, int *i);
t_item	*item_lstlast(t_item *lst);

void	get_screen_vec(t_vec *z_ax, t_vec *x_ax, t_vec *y_ax);
void	throw_rays(t_sc *sc, t_point *start, t_point *ctx, t_point *cty);

#endif
