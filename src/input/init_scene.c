/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:37:09 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/12 11:08:06 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

/*It sets all t_amb variables. Returns 1 with fail and 0 with success*/
int	get_ambient(char *line, int i, t_amb *amb)
{
	if (amb->ratio != -1)
		return (ft_dprintf(2, REPE, "A"), 1);
	skip_space(line, &i);
	if (!line[i])
		return (ft_dprintf(2, LINE, line), 1);
	amb->ratio = check_range(line, 'a', i);
	while (line[i] && !is_whitespace(line[i]))
		i++;
	if (amb->ratio == -2)
		return (1);
	skip_space(line, &i);
	if (!set_rgb(amb->rgb, line, i))
		return (1);
	return (0);
}

/*It sets all t_cam variables. Returns 1 with fail and 0 with success*/
int	get_camera(char *line, int i, t_cam *cam)
{
	if (cam->fov != -1)
		return (ft_dprintf(2, REPE, "C"), 1);
	skip_space(line, &i);
	if (!line[i])
		return (ft_dprintf(2, LINE, line), 1);
	if (init_vec(&cam->pos, line, &i, 0)
		|| init_vec(&cam->nov, line, &i, 'n'))
		return (1);
	skip_space(line, &i);
	cam->fov = check_range(line, 'f', i);
	if (cam->fov == -2)
		return (1);
	if (cam->fov != (int)cam->fov)
		return (ft_dprintf(2, INT, line), 1);
	cam->fov = cam->fov * M_PI / 180;
	return (0);
}

/*It sets all t_ligth variables. Returns 1 with fail and 0 with success*/
int	get_light(char *line, int i, t_light *light)
{
	if (light->b != -1)
		return (ft_dprintf(2, REPE, "L"), 1);
	skip_space(line, &i);
	if (!line[i])
		return (ft_dprintf(2, LINE, line), 1);
	if (init_vec(&light->pos, line, &i, 0))
		return (1);
	skip_space(line, &i);
	light->b = check_range(line, 'b', i);
	if (light->b == -2)
		return (1);
	while (line[i] && !is_whitespace(line[i]) && line[i] != ',')
		i++;
	if (!set_rgb(light->rgb, line, i))
		return (1);
	return (0);
}
