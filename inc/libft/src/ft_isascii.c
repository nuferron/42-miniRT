/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:55:56 by nuferron          #+#    #+#             */
/*   Updated: 2023/10/28 22:52:31 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
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
		if (ft_isascii(a[0][0]) != isascii(a[0][0]))
			return (printf("%sYOU'VE FAILED THE TEST \"%c\"\n", RED, a[0][0]));
	}
	if (ft_isascii('\0') != isascii('\0'))
		return (printf("%sYOU'VE FAILED THE TEST \"\\0\"%s\n", RED, RESET));
	if (ft_isascii('\200') != isascii('\200'))
		return (printf("%sYOU'VE FAILED THE TEST \"\\200\"%s\n", RED, RESET));
	if (ft_isascii('`') != isascii('`'))
		return (printf("%sYOU'VE FAILED THE TEST \"`\"%s\n", RED, RESET));
	if (ft_isascii('$') != isascii('$'))
		return (printf("%sYOU'VE FAILED THE TEST \"$\"%s\n", RED, RESET));
	if (ft_isascii('a') != isascii('a'))
		return (printf("%sYOU'VE FAILED THE TEST \"a\"%s\n", RED, RESET));
	if (ft_isascii('3') != isascii('3'))
		return (printf("%sYOU'VE FAILED THE TEST \"3\"%s\n", RED, RESET));
	return (printf("%sYOU'VE PASSED ALL THE TESTS! 🤩\n%s", GREEN, RESET));
}*/
