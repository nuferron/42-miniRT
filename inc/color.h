/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:51:08 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/21 16:58:15 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

unsigned int	rgb_to_hex(int *rgb);
//void			color_intensity(int *rgb, float intensity);
void			rerange_rgb(int *color);
//void			add_color(int *color, int *add);
unsigned int	add_color(unsigned int c1, unsigned int c2);
unsigned int	color_mult(unsigned int c1, unsigned int c2);
unsigned int	color_x_fact(unsigned int c, float n);
void			multiply_color(int *color, int *mult);

#endif
