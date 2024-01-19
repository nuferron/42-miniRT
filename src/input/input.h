/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:04:16 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/18 18:05:33 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
#define INPUT_H

#include "miniRT.h"

/* CHECKING INPUT + INITIALIZING STRUCTS */
int		check_input(int argc, char **argv, t_sc *sc);
int		get_ambient(char *line, int i, t_amb *amb);
int		get_camera(char *line, int i, t_cam *cam);
int		get_light(char *line, int i, t_light *light);
int		get_sphere(char *line, int i, t_item *sp);
int		get_plane(char *line, int i, t_item *pl);
int		get_cylinder(char *line, int i, t_item *cy);

/* INITIALIZE STRUCTS VARIABLES */
float	check_range(char *line, char type, int i);
int		init_vec(t_vec *vec, char *line, int *i, char t);
int		set_rgb(int *rgb, char *line, int i);
void	coord_transformation(t_sc *sc);

#endif
