/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 00:15:43 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 20:21:41 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_intlen(int num)
{
	int	counter;

	counter = 1;
	while (num / 10 != 0)
	{
		num = num / 10;
		counter++;
	}
	return (counter);
}

static char	*ft_conversion(int num, int sign, char *str)
{
	int	i;

	if (sign != -1)
		i = ft_intlen(num);
	else
		i = ft_intlen(num) + 1;
	if (num > 9)
		ft_conversion(num / 10, sign, str);
	num = num % 10 + '0';
	str[i - 1] = num;
	return (str);
}

static char	*ft_malloc_protection(int n)
{
	char	*str;

	if (n > 0)
		str = (char *)malloc(sizeof(char) * (ft_intlen(n) + 1));
	else
		str = (char *)malloc(sizeof(char) * (ft_intlen(n) + 2));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		nlen;

	sign = 1;
	nlen = ft_intlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	str = ft_malloc_protection(n);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		sign = -1;
		str[nlen + 1] = '\0';
	}
	else
		str[nlen] = '\0';
	ft_conversion(n, sign, str);
	return (str);
}
