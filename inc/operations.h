/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:27:20 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/27 18:20:09 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

typedef struct s_vec t_vec;
typedef struct s_vec t_point;

/****** VECTOR UTILS: creation, normalization & dot & cros prod ***********/
t_vec	vec_new(double x, double y, double z);
double	dot_prod(t_vec *a, t_vec *b);
t_vec	cross_prod(t_vec *v1, t_vec *v2);
double	vec_mod(t_vec *v);		//returns the length of the vector
t_vec	unit_vector(t_vec *v);	//normalizes vector v and returns a new vector

/****** VECTOR UTILS 2: addition and substraction *****************/
//returns the sum of two vectors
t_vec	sum_vec(t_vec *a, t_vec *b);
// returns the substraction of from - what
t_vec	substr_vec(t_vec *from, t_vec *what);
void	substr_new(t_vec *from, t_vec *what);
// returns a distance from the point1 to the point2
double	dist(t_point *point1, t_point *point2);
//normalizes vector n
void	norm_vector(t_vec *n);

/****** VECTOR UTILS 3: multiplication and division *****************/
// returns a the vector v multiplied by the float "factor"
t_vec	mult_new(t_vec *v, double factor);
// changes the vector v multiplying it by a factor
void	mult_fac(t_vec *v, double *factor);
// returns a the vector, that is a multiplication of v1 and v2
t_vec	mult_vec(t_vec *v1, t_vec *v2);
// returns a the vector v divided by the float "factor"
t_vec	div_new(t_vec *v, double *factor);
// changes the vector v dividing it by a factor
void	div_fac(t_vec *v, double *factor);


void	opp_vec(t_vec *v);

#endif
