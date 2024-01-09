/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:43:06 by nuferron          #+#    #+#             */
/*   Updated: 2023/10/28 23:27:01 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	neg;

	i = 0;
	nb = 0;
	neg = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * neg);
}
/*
#include <stdio.h>
int	test(char *str)
{
	if (ft_atoi(str) != atoi(str))
	{
		printf("%sYOU'VE FAILED THE TEST %s: YOU'VE RETURNED %d \
				INSTEAD OF %d\n", RED, str, ft_atoi(str), atoi(str));
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	if (argc != 1)
	{
		while (++i < argc)
			j += test(argv[i]);
	}
	j += test("2147483647");
	j += test("-2147483648");
	j += test("0");
	j += test("10");
	j += test("----10");
	j += test("+-200");
	j += test("+300");
	j += test("-15");
	j += test("123hola567");
	j += test("0000000000001");
	j += test("       5     ");
	j += test("		15");
	j += test("-   3");
	if (j == 0)
		printf("%sCONGRATULATIONS! YOU'VE PASSED ALL THE TESTS! 🤩\n", GREEN);
	return (0);
}*/
