/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:17:27 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 21:18:17 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	print_pointer_hexadecimal(unsigned long long n)
{
	int			hex_value;
	int			nbytes;
	int			w_protection;
	static char	*hex_base = "0123456789abcdef";

	nbytes = 0;
	hex_value = hex_base[n % 16];
	if (n / 16 > 0)
	{
		n = n / 16;
		w_protection = print_pointer_hexadecimal(n);
		if (w_protection == -1)
			return (-1);
		nbytes += w_protection;
	}
	w_protection = write(1, &hex_value, 1);
	if (w_protection == -1)
		return (-1);
	nbytes += w_protection;
	return (nbytes);
}

int	print_pointer(unsigned long long num)
{
	int	len;
	int	w_protection;

	w_protection = write(1, "0x", 2);
	if (w_protection == -1)
		return (-1);
	len = w_protection;
	if (num == 0)
	{
		w_protection = write(1, "0", 1);
		if (w_protection == -1)
			return (-1);
		len += w_protection;
		return (len);
	}
	w_protection = print_pointer_hexadecimal(num);
	if (w_protection == -1)
		return (-1);
	len += w_protection;
	return (len);
}
