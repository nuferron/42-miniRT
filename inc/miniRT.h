/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:59:25 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/06 16:26:09 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#include <math.h>
#include <fcntl.h>
#include <stdbool.h>

#include "operations.h"
#include "mlx_rt.h"
#include "intersections.h"
#include "libft/inc/libft.h"
#include "ft_dprintf/inc/libftprintf.h"

typedef struct s_amb //AMBIENT LIGHTNING
{
	float	ratio;	//ambient lightning ratio [0.0 - 1.0]
	int		rgb[3];
}	t_amb;

typedef struct s_cam //CAMERA
{
	t_point	pos;	//center point
	t_vec	nov;	//3D normalized orientation vector for x [-1.0 - 1.0]
	float	fov;	//horizontal field of view taken DEG [0 - 180] saved in RAD
}	t_cam;

typedef struct s_light //LIGHT
{
	t_point			pos;	//center point
	float			b;		//light brightness ratio [0.0 - 1.0]
	int				rgb[3];
	struct s_light	*next;
}	t_light;

typedef struct s_screen
{
	t_point	center;
	t_vec	x_ax;
	t_vec	y_ax;
	t_point	start;
	float	width;
	float	height;
	float	pix_rat;
}	t_screen;

typedef struct s_sc
{
	t_mlx		mlx; //mlx_rt.h
	t_screen	screen;
	t_ray		ray;
	t_light		*light;
	t_amb		amb;
	t_cam		cam;
	t_item		*objs; //items.h
}	t_sc;

/* MEMORY UTILS */
void	sp_free(t_obj *obj);
void	pl_free(t_obj *obj);
void	cy_free(t_obj *obj);
void	cone_free(t_obj *obj);

/* UTILS */
int		is_float(char *str); //not in utils
int		skip_space(char *line, int *i);
int		skip_number(char *line, int *i);
void	skip_sp_num_sp(char *line, int *i);
t_item	*item_lstlast(t_item *lst);

void	get_screen_vec(t_vec *z_ax, t_vec *x_ax, t_vec *y_ax);
void	throw_rays(t_sc *sc, t_point *start, t_point *ctx, t_point *cty);
void	throw_first_ray(t_sc *sc, t_point *start, t_point *ctx, t_point *cty);
int		check_first_pix(t_sc *sc, t_point *ctx, t_point *cty);

#endif
