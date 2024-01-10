/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:37:09 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/10 22:10:29 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	get_ambient(char *line, int i, t_sc *sc)
{
	t_amb	*ambient;

	printf("GA: i = %d -> line[i] = |%s|\n", i, &line[i]);
	ft_atod("1.234");
	while (is_whitespace(line[i]))
		i++;
	printf("GA: i = %d -> line[i] = |%s|\n", i, &line[i]);
	if (!line[i])
		return (ft_dprintf(2, LINE, line), free(line), 1);
	if (line[i] != '0' || line[i] != '1')
		return (ft_dprintf(2, RANGE, line, "[0.0 - 1.0]"));// ft_strncmp
	ambient = ft_calloc(1, sizeof(t_amb));
	if (!ambient)
		exit(ft_dprintf(2, MEM));
	sc->amb = ambient;
	free(line);
	return (0);
}
