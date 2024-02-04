/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:59:25 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/04 22:40:05 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

/* vector_utils.c - vector operations  **************/
double	dot_product(t_vec *a, t_vec *b);	
double	vec_mod(t_vec v);					//returns the lenth of the vector
void	unit_vector(t_vec *v, t_vec *n);	//normalizes vector v and saves it in n

/* vector_utils2.c - vector operations  **************/
t_vec	sum_vec(t_vec a, t_vec b);			// returns the sum of two vectors
t_vec	substr_vec(t_vec from, t_vec what);	// returns the substruction of the vector "what" from the vector "from"
t_vec	mult_fac(t_vec v, double factor);	// return a the vector v multiplied by the float "factor"
t_vec	div_fac(t_vec v, double factor);	// return a the vector v divided by the float "factor"
double	dist(t_vec point1, t_vec point2);	// returns a distance from the point1 to the point2
/****************************************************/

#endif
