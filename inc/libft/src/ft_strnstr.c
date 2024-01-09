/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:33:30 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 20:21:42 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	find_needle(const char *hay, size_t i, const char *nd, size_t len)
{
	int	j;

	j = 0;
	while (hay[i] && nd[j] && i < len)
	{
		if (hay[i] == nd[j])
		{
			if (nd[j + 1] == '\0')
				return (1);
			j++;
		}
		else
			return (0);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	hay_len;

	i = 0;
	j = 0;
	hay_len = ft_strlen(haystack);
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (i < hay_len && i < len)
	{
		if (find_needle(haystack, i, needle, len) == 1)
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}
