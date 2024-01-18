/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:57:27 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/16 17:25:01 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*It skips whitespaces*/
void	skip_space(char *line, int *i)
{
	while (line[*i] && is_whitespace(line[*i]))
		(*i)++;
}

/*It skips number including floats*/
void	skip_number(char *line, int *i)
{
	while (line[*i] && ft_isdigit(line[*i]))
	{
		(*i)++;
		if (line[*i] == '.')
			(*i)++;
	}
}
