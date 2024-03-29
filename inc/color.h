/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:51:08 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/07 17:49:01 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

void			get_color(t_sc *sc, t_item *objs, t_hit *h);

unsigned int	rgb_to_hex(int *rgb);
unsigned int	add_color(unsigned int c1, unsigned int c2);
unsigned int	color_mult(unsigned int c1, unsigned int c2);
unsigned int	color_x_fact(unsigned int c, float n);
unsigned int	color_mean(unsigned int c1, unsigned int c2);

#endif
