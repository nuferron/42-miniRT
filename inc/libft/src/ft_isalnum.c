/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:23:35 by nuferron          #+#    #+#             */
/*   Updated: 2023/10/28 22:51:59 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(int argc, char **a)
{
	if (argc > 2)
		return (printf("%sINVALID NUMEBR OF ARGUMENTS%s\n", RED, RESET));
	if (argc == 2)
	{
		if (ft_isalnum(a[0][0]) != isalnum(a[0][0]))
			return (printf("%sYOU'VE FAILED THE TEST \"%c\"\n", RED, a[0][0]));
	}
	if (ft_isalnum('\0') != isalnum('\0'))
		return (printf("%sYOU'VE FAILED THE TEST \"\\0\"%s\n", RED, RESET));
	if (ft_isalnum('\200') != isalnum('\200'))
		return (printf("%sYOU'VE FAILED THE TEST \"\\200\"%s\n", RED, RESET));
	if (ft_isalnum('3') != isalnum('3'))
		return (printf("%sYOU'VE FAILED THE TEST \"3\"%s\n", RED, RESET));
	if (ft_isalnum('A') != isalnum('A'))
		return (printf("%sYOU'VE FAILED THE TEST \"A\"%s\n", RED, RESET));
	return (printf("%sYOU'VE PASSED ALL THE TESTS! 🤩\n%s", GREEN, RESET));
}*/
