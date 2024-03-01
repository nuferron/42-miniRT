/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:38:35 by nzhuzhle          #+#    #+#             */
/*   Updated: 2024/03/01 19:27:49 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_RT_H
# define MLX_RT_H

# define WIDTH 1200
# define HEIGHT 800
# define FOCAL	150
# define ESC 53

# include "./mlx/mlx.h"
typedef struct s_sc t_sc;

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
