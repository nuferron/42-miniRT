/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:22:33 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/09 22:06:29 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		len;

	len = ft_strlen((char *)s1) + 1;
	ptr = (char *) malloc(len * sizeof (char));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1, len);
	return (ptr);
}
