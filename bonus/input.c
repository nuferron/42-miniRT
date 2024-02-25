/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:47:50 by nuferron          #+#    #+#             */
/*   Updated: 2024/02/23 18:37:54 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdlib.h>

t_light	*add_light(t_light *first)
{
	t_light	*last;
	t_light	*new;

	last = first;
	new = calloc(1, sizeof(t_light));
	if (!new)
		exit(ft_dprintf(2, MEM));
	while (last->next)
		last = last->next;
	last->next = new;
	return (new);
}

int	get_all_lights(char *line, int i, t_light *light)
{
	t_light	*last;

	if (light->b != -1)
		last = add_light(light);
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
