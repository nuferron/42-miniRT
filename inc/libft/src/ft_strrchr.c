/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:34:10 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 20:21:42 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*aux_s;

	aux_s = (char *) s;
	len = ft_strlen(aux_s);
	while (len > 0 && aux_s[len] != (unsigned char)c)
		len--;
	if (aux_s[len] == (unsigned char)c)
		aux_s = &aux_s[len];
	else
		aux_s = NULL;
	return (aux_s);
}
