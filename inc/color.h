/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:51:08 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/21 10:51:48 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

unsigned int	rgb_to_hex(int *rgb);
void			color_intensity(int *rgb, float intensity);
void			rerange_rgb(int *color);
void			add_color(int *color, int *add);
void			multiply_color(int *color, int *mult);

#endif
