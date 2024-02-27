/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:04:16 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/27 18:27:53 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include "miniRT.h"

#define LIGHT (int[3]){128,0,128}

/* CHECKING INPUT + INITIALIZING STRUCTS */
/* init_scene.c */
int		get_ambient(char *line, int i, t_amb *amb);
int		get_camera(char *line, int i, t_cam *cam);
int		get_light(char *line, int i, t_light *light);

/* init_objects.c */
int		get_sphere(char *line, int i, t_sc *sc);
int		get_plane(char *line, int i, t_sc *sc);
int		get_cylinder(char *line, int i, t_sc *sc);
t_item	*add_obj(t_item *item, t_sc *sc);

/* init_utils.c - INITIALIZE STRUCTS VARIABLES */
float	check_range(char *line, char type, int i);
int		init_vec(t_vec *vec, char *line, int *i);
int		set_rgb(int *rgb, char *line, int i);
void	translation(t_vec *new_origin, t_vec *p);
// void	coord_transformation(t_sc *sc); - is in this file

/*mand_check.c - MANDATORY - calls parsing ft for each element*/
/*bonus/input.c - BONUS - calls parsing ft for each element*/
int		check_content(t_sc *sc, char *line);

/* translation.c - coord translation for different types of unions */
void	sph_translation(t_obj *obj, t_sc *sc);
void	pl_translation(t_obj *obj, t_sc *sc);
void	cy_translation(t_obj *obj, t_sc *sc);

/* check_input.c - parsing + initalization*/
int		check_input(int argc, char **argv, t_sc *sc);

#endif
