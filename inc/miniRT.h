/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:59:25 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/18 20:19:58 by nzhuzhle         ###   ########.fr       */
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

/* MEMORY UTILS */
void	free_all(t_sc *sc);
void	add_obj(t_item *item);

/* UTILS */
int		is_float(char *str);
void	skip_space(char *line, int *i);
void	skip_number(char *line, int *i);

#endif
