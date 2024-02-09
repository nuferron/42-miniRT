/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:17:32 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/09 18:59:17 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

#include "mlx_rt.h"

/* A variable structure for sphere intersection */
typedef struct s_vars
{
	t_vec	oc;		//	ray origin - sphere center
	t_vec	vo;		//	ray vector - ray origin
	double	vo_dot;	//	dot product (vo, vo) - iquals to k1
	double	k2;		//	2 * dot product (oc, vo)
	double	discr;	//	discriminant
}	t_vars;
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

typedef struct s_vec t_point;

typedef struct s_amb //AMBIENT LIGHTNING
{
	float	ratio;	//ambient lightning ratio [0.0- 1.0]
	int		rgb[3];
}	t_amb;

typedef struct s_cam //CAMERA
{
	t_point	pos;	//center point
	t_vec	nov;	//3D normalized orientation vector for x [-1.0 - 1.0]
	float	fov;	//horizontal field of view taken DEG [0 - 180] saved as RAD
}	t_cam;

typedef struct s_light
{
	t_point	pos;	//center point
	float	b;		//light brightness ratio [0.0 - 1.0]
	int		rgb[3];	//(bonus)
}	t_light;

typedef struct s_sp //SPHERE
{
	t_point	pos;	//center point
	float	r;		//radius
	int		rgb[3];
}	t_sp;

typedef struct s_pl //PLANE
{
	t_point	pos;	//center point
	t_vec	nov;	//3D normalized orientation vector for x [-1.0 - 1.0]
	int		rgb[3];
}	t_pl;

typedef struct s_cy //CYLINDER
{
	t_point	pos;	//center point
	t_vec	nov;	//3D normalized orientation vector for x [-1.0 - 1.0]
	float	r;		//radius
	float	h;		//height
	int		rgb[3];
}	t_cy;

typedef struct s_ray
{
	t_point	ray_orig;	// the coordinates of the screen point or (0,0,0) ???
	t_vec	ray_vec;	// the ray vector
	t_point	hit;
	double	dist;		// the minimal distance
}	t_ray;

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
	int		w;		// not sure about it
	int		h;		// not sure about it
	int		color;
}	t_mlx;

typedef struct s_screen
{
	t_point	center;
	float	width;
	float	pix_rat;
}	t_screen;

typedef struct s_sc //SCENE
{
	t_mlx		mlx;
	t_screen	screen;
	t_light		light;
	t_amb		amb;
	t_cam		cam;
	t_item		sp;
	t_item		pl;
	t_item		cy;
}	t_sc;


#endif
