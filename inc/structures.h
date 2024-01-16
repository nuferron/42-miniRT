/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:17:32 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/16 14:31:38 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_item
{
	void	*obj;
	size_t	size;
	int		total;
} t_item;

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
} t_vec;

typedef struct s_amb	//AMBIENT LIGHTNING
{
	float	ratio;	//ambient lightning ratio [0.0- 1.0]
	int		rgb[3];
} t_amb;

typedef struct s_cam	//CAMERA
{
	t_vec	pos;
	t_vec	nov;	//3D normalized orientation vector for x [-1.0 - 1.0]
	float	fov;	//horizontal field of view in degrees [0 - 180]
} t_cam;

typedef struct s_light
{
	t_vec	pos;
	float	b;		//light brightness ratio [0.0 - 1.0]
	int		rgb[3];	//(bonus)
} t_light;

typedef struct s_sp		//SPHERE
{
	t_vec	pos;
	float	d;		//diameter
	int		rgb[3];
} t_sp;

typedef struct s_pl		//PLANE
{
	t_vec	pos;
	t_vec	nov;	//3D normalized orientation vector for x [-1.0 - 1.0]
	int		rgb[3];
} t_pl;

typedef struct s_cy		//CYLINDER
{
	t_vec	pos;
	t_vec	nov;	//3D normalized orientation vector for x [-1.0 - 1.0]
	float	d;		//diameter
	float	h;		//height
	int		rgb[3];
} t_cy;

typedef struct s_sc		//SCENE
{
	t_amb		amb;
	t_cam		cam;
	t_light		light;
	t_item		sp;
	t_item		pl;
	t_item		cy;
} t_sc;

#endif
