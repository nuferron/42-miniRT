/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:27:29 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/04 16:34:02 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITEMS_H
# define ITEMS_H

typedef struct s_ray t_ray;
typedef struct s_item t_item;
typedef struct s_hit t_hit;

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
//	int		flag;	//0 - winner point is on the body, 1 - winner point is on a plane
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

#endif
