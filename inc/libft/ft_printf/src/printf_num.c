/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:17:27 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 21:17:39 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	print_num_digits(int num)
{
	int	aux;
	int	nbytes;
	int	w_protection;

	nbytes = 0;
	aux = num % 10 + '0';
	if (num / 10 > 0)
	{
		num = num / 10;
		w_protection = print_num_digits(num);
		if (w_protection == -1)
			return (-1);
		nbytes += w_protection;
	}
	if (write(1, &aux, 1) == -1)
		return (-1);
	nbytes++;
	return (nbytes);
}

int	print_num(int num)
{
	int	nbytes;
	int	w_protection;

	nbytes = 0;
	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (num == 0)
		return (write(1, "0", 1));
	if (num < 0)
	{
		nbytes = write(1, "-", 1);
		if (nbytes == -1)
			return (-1);
		num = -num;
	}
	w_protection = print_num_digits(num);
	if (w_protection == -1)
		return (-1);
	nbytes += w_protection;
	return (nbytes);
}
