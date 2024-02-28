/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:17:32 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/28 19:01:14 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

#include "mlx_rt.h"

enum	e_type
{
	sph = 0,
	pla = 1,
	cyl = 2,
	disk = 3,
	cone = 4
};

/* Structure for coordinates ("absolute" or normalized) */
typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

typedef struct s_vec t_point;

//  ----------------------------------------------------------------/
//	RAYS, HITS -----------------------------------------------------/
/* A variable structure for sphere intersection */
typedef struct s_vars
{
	t_vec	oc;		//	ray origin - shape center
	double	k1;
	double	k2;		//	2 * dot product (oc, vo)
	double	k3;
	double	discr;	//	discriminant
}	t_vars;

typedef struct s_item t_item;
typedef struct s_hit
{
	t_point		p;		// the minimal point of intersection
	t_vec		norm;	// normalized vector of the hit
	t_item		*obj;	// pointer to the winner object
	int			*rgb;
	bool		obst; 	// obst = 0 if there is access to light
	enum e_type	type;
}	t_hit;

typedef struct s_ray
{
	t_hit	hit;	// info about the record hit
	t_point	zero;	// the coordinates of the camera
	t_vec	norm;	// the normalized ray vector
	t_point	orig;	// point on the screen
	t_point	p;	// variable - intersection point
	double	t[2];	// variable - distance coefficient to the intersection point
	double	dist;	// the minimal distance
}	t_ray;
//	RAYS, HITS -----------------------------------------------------/
//  ----------------------------------------------------------------/

//  ----------------------------------------------------------------/
//	OBJECTS SET UP -------------------------------------------------/
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
	float	prod;	// dot product of pos and nov
	int		rgb[3];
}	t_pl;

typedef struct s_cy //CYLINDER
{
	t_point	pos;	//bottom point
	t_vec	nov;	//3D normalized orientation vector for x [-1.0 - 1.0]
	t_point	lim;	//upper point
	float	prod[2];	// dot products of pos and nov for the planes
	float	m[2];	//solution to count the normal	
	float	r;		//radius
	float	h;		//height
	int		rgb[3];
}	t_cy;

typedef struct s_co //CONO
{
	t_point	pos;	//top point
	t_vec	nov;	//3D normalized orientation vector for x [-1.0 - 1.0]
	t_point	lim;	//bottom point
	float	prod;	// dot product of pos and nov for the plane
	float	m[2];	//solution to count the normal	
	float	r;		//radius
	float	h;		//height
	float	tg;		//tangent of the half angle
	int		rgb[3];
}	t_co;

/* Union that can contain a t_sp, a t_pl or a t_cy pointer -  obj.sp/pl/cy */
typedef union u_obj
{
	t_sp	*sp;
	t_pl	*pl;
	t_cy	*cy;
	t_co	*co;
}	t_obj;

typedef struct s_item
{
	t_obj			type;
	void			(*intersect)(t_obj *, t_ray *, t_item *);
	void			(*trans)(t_obj *obj, t_sc *sc);
	void			(*obj_free)(t_obj *obj);
	void			(*get_norm)(t_obj *, t_hit *);
	struct s_item	*next;
}	t_item;
//	OBJECTS SET UP -------------------------------------------------/
//  ----------------------------------------------------------------/

//	SCENE SET UP ---------------------------------------------------/
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
	struct s_light	*next;
}	t_light;
//	SCENE SET UP ---------------------------------------------------/
//  ----------------------------------------------------------------/

//  SCREEN SET UP --------------------------------------------------/
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
//  SCREEN SET UP --------------------------------------------------/
//  ----------------------------------------------------------------/

//	MLX AND IMAGE --------------------------------------------------/
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
	t_img			img;
	void			*init;
	void			*win;
	int				w;
	int				h;
	unsigned int	color;
}	t_mlx;
//	MLX AND IMAGE --------------------------------------------------/
//  ----------------------------------------------------------------/

//	SCENE - MAIN STRUCTURE------------------------------------------/
typedef struct s_sc
{
	t_mlx		mlx;
	t_screen	screen;
	t_light		light;
	t_amb		amb;
	t_cam		cam;
	t_item		*objs;
}	t_sc;

#endif
