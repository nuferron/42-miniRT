/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:38:35 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/03/06 22:12:01 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_RT_H
# define MLX_RT_H

# define WIDTH 1900
# define HEIGHT 1000
# define FOCAL	150
# define ESC 53

# include "./mlx/mlx.h"
typedef struct s_sc t_sc;

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

/***** mlx.c **********/
int		init_mlx(t_sc *sc);
void	maintain_mlx(t_sc *sc);
int		ft_key_hook(int key, t_sc *sc);
int 	ft_error_mlx(t_sc *sc, int flag);
int 	ft_exit_mlx(t_sc *sc);
/*********************/

/***** draw.c **********/
void	draw_scene(t_sc *sc);
void	put_pixel(t_sc *sc);


#endif
