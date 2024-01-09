/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:34:31 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/09 22:05:35 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*aux_src;
	unsigned char	*aux_dst;
	size_t			i;

	aux_src = (unsigned char *) src;
	aux_dst = (unsigned char *) dst;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		aux_dst[i] = aux_src[i];
		i++;
	}
	return (dst);
}
