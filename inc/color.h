/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:51:08 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/23 18:28:01 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

void			obj_color(t_amb *amb, t_light l, unsigned int *c, t_hit *h);

unsigned int	rgb_to_hex(int *rgb);
unsigned int	add_color(unsigned int c1, unsigned int c2);
unsigned int	color_mult(unsigned int c1, unsigned int c2);
unsigned int	color_x_fact(unsigned int c, float n);

#endif
