/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:10:21 by nuferron          #+#    #+#             */
/*   Updated: 2023/10/28 22:55:39 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
		if (ft_isprint(a[0][0]) != isprint(a[0][0]))
			return (printf("%sYOU'VE FAILED THE TEST \"%c\"\n", RED, a[0][0]));
	}
	if (ft_isprint('\0') != isprint('\0'))
		return (printf("%sYOU'VE FAILED THE TEST \"\\0\"%s\n", RED, RESET));
	if (ft_isprint('\200') != isprint('\200'))
		return (printf("%sYOU'VE FAILED THE TEST \"\\200\"%s\n", RED, RESET));
	if (ft_isprint('3') != isprint('3'))
		return (printf("%sYOU'VE FAILED THE TEST \"3\"%s\n", RED, RESET));
	if (ft_isprint(5) != isprint(5))
		return (printf("%sYOU'VE FAILED THE TEST \"A\"%s\n", RED, RESET));
	return (printf("%sYOU'VE PASSED ALL THE TESTS! 🤩\n%s", GREEN, RESET));
}*/
