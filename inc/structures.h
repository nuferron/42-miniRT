/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:17:32 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/07 16:16:00 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

#include "mlx_rt.h"

/*Structure that can contain a t_sp, a t_pl or a t_cy pointer in void *obj
Size is a sizeof the structure and total the number we have of them*/
typedef struct s_item
{
	void	*obj;
	int		total;
	size_t	size;
}	t_item;

/*Structure for coordinates ("absolute" or normalized)*/
typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

typedef struct s_amb //AMBIENT LIGHTNING
{
	float	ratio;	//ambient lightning ratio [0.0- 1.0]
	int		rgb[3];
}	t_amb;

typedef struct s_cam //CAMERA
{
	t_vec	pos;	//center point
	t_vec	nov;	//3D normalized orientation vector for x [-1.0 - 1.0]
	float	fov;	//horizontal field of view in degrees [0 - 180]
}	t_cam;

typedef struct s_light
{
	t_vec	pos;	//center point
	float	b;		//light brightness ratio [0.0 - 1.0]
	int		rgb[3];	//(bonus)
}	t_light;

typedef struct s_sp //SPHERE
{
	t_vec	pos;	//center point
	float	r;		//radiusr
	int		rgb[3];
}	t_sp;

typedef struct s_pl //PLANE
{
	t_vec	pos;	//center point
	t_vec	nov;	//3D normalized orientation vector for x [-1.0 - 1.0]
	int		rgb[3];
}	t_pl;

typedef struct s_cy //CYLINDER
{
	t_vec	pos;	//center point
	t_vec	nov;	//3D normalized orientation vector for x [-1.0 - 1.0]
	float	r;		//radius
	float	h;		//height
	int		rgb[3];
}	t_cy;

typedef struct s_img
{
	void	*ipt;
	char	*ppt;
	int		bits;
	int		endian;
	int		line;
}	t_img;

typedef struct s_mlx
{
	t_img	img;
	void	*init;
	void	*win;
	int		x;
	int		y;
	int		color;
}	t_mlx;

typedef struct s_screen
{
	t_vec	center;
	float	width;
	float	pix_rat;
}	t_screen;

typedef struct s_sc //SCENE
{
	t_cam		cam;
	t_amb		amb;
	t_light		light;
	t_item		sp;
	t_item		pl;
	t_item		cy;
	t_mlx		mlx;
	t_screen	screen;
}	t_sc;

#endif
