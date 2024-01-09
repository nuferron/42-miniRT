/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:41:25 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 20:21:42 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*aux_src;
	unsigned char	*aux_dst;

	aux_src = (unsigned char *)src;
	aux_dst = (unsigned char *)dst;
	if (!len || (!dst && !src))
		return (dst);
	if (dst > src)
	{
		while (len > 0)
		{
			aux_dst[len - 1] = aux_src[len -1];
			len--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
