/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:12:16 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/16 16:58:34 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*It checks if the whole string is a float
 returns 0 if it's not a float and 1 if it is*/
int	is_float(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] == '.' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] && !is_whitespace(str[i]) && str[i] != ',')
		return (0);
	return (1);
}
