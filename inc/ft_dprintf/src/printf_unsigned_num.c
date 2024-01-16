/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned_num.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:17:27 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/09 22:19:40 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_unsigned_num(int fd, unsigned int num)
{
	int	nbytes;
	int	aux;
	int	w_protection;

	nbytes = 0;
	aux = num % 10 + '0';
	if (num / 10 > 0)
	{
		num = num / 10;
		w_protection = print_unsigned_num(fd, num);
		if (w_protection == -1)
			return (-1);
		nbytes += w_protection;
	}
	if (write(fd, &aux, 1) == -1)
		return (-1);
	nbytes++;
	return (nbytes);
}
