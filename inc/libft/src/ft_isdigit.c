/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:59:13 by nuferron          #+#    #+#             */
/*   Updated: 2023/10/28 22:53:43 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isdigit(int num)
{
	if (num >= '0' && num <= '9')
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
		if (ft_isdigit(a[0][0]) != isdigit(a[0][0]))
			return (printf("%sYOU'VE FAILED THE TEST \"%c\"\n", RED, a[0][0]));
	}
	if (ft_isdigit('\0') != isdigit('\0'))
		return (printf("%sYOU'VE FAILED THE TEST \"\\0\"%s\n", RED, RESET));
	if (ft_isdigit('\200') != isdigit('\200'))
		return (printf("%sYOU'VE FAILED THE TEST \"\\200\"%s\n", RED, RESET));
	if (ft_isdigit('3') != isdigit('3'))
		return (printf("%sYOU'VE FAILED THE TEST \"3\"%s\n", RED, RESET));
	if (ft_isdigit('0') != isdigit('0'))
		return (printf("%sYOU'VE FAILED THE TEST \"0\"%s\n", RED, RESET));
	return (printf("%sYOU'VE PASSED ALL THE TESTS! 🤩\n%s", GREEN, RESET));
}*/
