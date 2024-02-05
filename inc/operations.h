/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:27:20 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/05 17:20:27 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

typedef struct s_vec t_vec;
typedef struct s_vec t_point;

/* vector_utils2.c - vector operations  **************/
t_vec	sum_vec(t_vec *a, t_vec *b);		// returns the sum of two vectors
t_vec	substr_vec(t_vec *from, t_vec *what);	// returns the substruction of the vector "what" from the vector "from"
double	dist(t_point *point1, t_point *point2);	// returns a distance from the point1 to the point2
/****************************************************/

/* vector_utils3.c - vector operations  **************/
t_vec	mult_new(t_vec *v, double factor);	// returns a the vector v multiplied by the float "factor"
t_vec	mult_fac(t_vec *v, double factor);	// changes the vector v multiplying it by a factor 
t_vec	div_new(t_vec *v, double factor);	// returns a the vector v divided by the float "factor"
t_vec	div_fac(t_vec *v, double factor);	// changes the vector v dividing it by a factor 

#endif