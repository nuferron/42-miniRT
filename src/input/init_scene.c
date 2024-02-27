/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:37:09 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/27 18:27:32 by nuferron         ###   ########.fr       */
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
	if (init_vec(&cam->pos, line, &i)
		|| init_vec(&cam->nov, line, &i))
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
static t_light	*add_light(t_light *first)
{
	t_light	*last;
	t_light	*new;

	last = first;
	new = ft_calloc(1, sizeof(t_light));
	if (!new)
		exit(ft_dprintf(2, MEM));
	while (last->next)
		last = last->next;
	last->next = new;
	return (new);
}

/*Initializes the light in a bonus way*/
int	get_light(char *line, int i, t_light *light)
{
	t_light	*last;

	if (light->b != -1)
		last = add_light(light);
	else
		last = light;
	skip_space(line, &i);
	if (!line[i])
		return (ft_dprintf(2, LINE, line), 1);
	if (init_vec(&last->pos, line, &i))
		return (1);
	skip_space(line, &i);
	last->b = check_range(line, 'b', i);
	if (last->b == -2)
		return (1);
	while (line[i] && !is_whitespace(line[i]) && line[i] != ',')
		i++;
	if (!set_rgb(last->rgb, line, i))
		return (1);
	return (0);
}
