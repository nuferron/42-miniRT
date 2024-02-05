/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:59:25 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/05 16:20:25 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "errors.h"
#include "structures.h"
#include "mlx_rt.h"
#include "libft/inc/libft.h"
#include "ft_dprintf/inc/libftprintf.h"

/* GETTING DATA */
int		check_input(int argc, char **argv, t_sc *sc);
void	coord_transformation(t_sc *sc);

/* MEMORY UTILS */
void	free_all(t_sc *sc);
void	add_obj(t_item *item);

/* UTILS */
int		is_float(char *str);
void	skip_space(char *line, int *i);
void	skip_number(char *line, int *i);

/* MATH UTILS */
double	exp_n(double b, int n);
double	exp_2(double b);

/* VECTOR UTILS */
void	unit_vector(t_vec *v1, t_vec *v2);

int	intersection_sp(t_item *item, t_vec *ray);

#endif
