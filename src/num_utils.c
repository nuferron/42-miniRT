/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:12:16 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/11 22:03:42 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*It checks if the whole string is a number, including floats
 returns 0 if it's not a number and 1 if it is*/
int	is_number(char *str)
{
	int	fl;

	fl = 0;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && ft_isdigit(*str) && fl < 2)
	{
		str++;
		if (*str == '.')
		{
			fl++;
			str++;
		}
	}
	if (*str && (!is_whitespace(*str) && *str != ','))
		return (0);
	return (1);
}
