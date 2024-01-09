/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex_cap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 00:03:59 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 21:18:57 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	hex_conversion_cap(unsigned int dec_num)
{
	static char	*hex_base = "0123456789ABCDEF";
	int			nbytes;
	int			hex_value;
	int			w_protection;

	hex_value = hex_base[dec_num % 16];
	nbytes = 0;
	if (dec_num / 16 > 0)
	{
		dec_num = dec_num / 16;
		w_protection = hex_conversion_cap(dec_num);
		if (w_protection == -1)
			return (-1);
		nbytes += w_protection;
	}
	if (write(1, &hex_value, 1) == -1)
		return (-1);
	nbytes++;
	return (nbytes);
}

int	print_hex_cap(unsigned int dec_num)
{
	if (dec_num == 0)
		return (write(1, "0", 1));
	return (hex_conversion_cap(dec_num));
}
