/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:30:52 by nuferron          #+#    #+#             */
/*   Updated: 2023/10/28 22:46:28 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
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
		if (ft_isalpha(a[0][0]) != isalpha(a[0][0]))
			return (printf("%sYOU'VE FAILED THE TEST \"%c\"\n", RED, a[0][0]));
	}
	if (ft_isalpha('\0') != isalpha('\0'))
		return (printf("%sYOU'VE FAILED THE TEST \"\\0\"%s\n", RED, RESET));
	if (ft_isalpha('A') != isalpha('A'))
		return (printf("%sYOU'VE FAILED THE TEST \"A\"%s\n", RED, RESET));
	if (ft_isalpha('b') != isalpha('b'))
		return (printf("%sYOU'VE FAILED THE TEST \"b\"%s\n", RED, RESET));
	if (ft_isalpha('$') != isalpha('$'))
		return (printf("%sYOU'VE FAILED THE TEST \"$\"%s\n", RED, RESET));
	return (printf("%sYOU'VE PASSED ALL THE TESTS! 🤩\n%s", GREEN, RESET));
}*/
