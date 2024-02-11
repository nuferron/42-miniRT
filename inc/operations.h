/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:27:20 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/02/11 18:23:46 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

typedef struct s_vec t_vec;
typedef struct s_vec t_point;

/* vector_utils.c - vector operations: products, norm  **************/
t_vec	vec_new(double x, double y, double z);
double	dot_prod(t_vec *a, t_vec *b);
t_vec	cross_prod(t_vec *v1, t_vec *v2);
double	vec_mod(t_vec *v);					//returns the length of the vector
void	unit_vector(t_vec *v, t_vec *n);	//normalizes vector v and saves it in n
/****************************************************/

/* vector_utils2.c - vector operations: +/-  **************/
t_vec	sum_vec(t_vec *a, t_vec *b);			// returns the sum of two vectors
t_vec	substr_vec(t_vec *from, t_vec *what);	// returns the substruction of the vector "what" from the vector "from"
double	dist(t_point *point1, t_point *point2);	// returns a distance from the point1 to the point2


/* vector_utils3.c - vector operations: multipliction, division  ***********/
t_vec	mult_new(t_vec *v, double *factor);	// returns a the vector v multiplied by the float "factor"
void	mult_fac(t_vec *v, double *factor);	// changes the vector v multiplying it by a factor 
t_vec	mult_vec(t_vec *v1, t_vec *v2);		// returns a the vector, that is a multiplication of v1 and v2
t_vec	div_new(t_vec *v, double *factor);	// returns a the vector v divided by the float "factor"
void	div_fac(t_vec *v, double *factor);	// changes the vector v dividing it by a factor 
/****************************************************/

#endif