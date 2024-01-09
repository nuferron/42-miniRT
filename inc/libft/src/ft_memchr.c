/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:08:53 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/09 22:05:22 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*aux;
	size_t			i;

	aux = (unsigned char *) s;
	i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			if (aux[i] == (unsigned char) c)
			{
				aux = &aux[i];
				return ((void *) aux);
			}
			else
				i++;
		}
	}
	aux = NULL;
	return ((void *) aux);
}
