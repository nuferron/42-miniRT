/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:23:28 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/10 22:11:49 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <float.h>

static double	get_floating(char *str)
{
	double	fl;
	int		len;

	fl = 0;
	if (!str)
		return (0);
	len = ft_strlen(str) - 1;
	while (len >= 0 && str[len] >= '0' && str[len] <= '9')
		fl = (fl / 10) + (str[len--] - '0');
	return (fl / 10);
}

int	float_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] >= '0' && str[len] <= '9')
		len++;
	return (len);
}

float	ft_atof(char *str)
{
	int		i;
	double	nb;
	double	neg;

	i = 0;
	nb = 0;
	neg = 1;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			neg = -neg;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9' && str[i] != '.')
		nb = (nb * 10) + (str[i++] - '0');
	if (str[i++] == '.')
		nb += get_floating(&str[i]);
	return ((float)(nb * neg));
}
