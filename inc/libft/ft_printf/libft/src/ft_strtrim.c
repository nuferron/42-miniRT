/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:36:56 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 20:21:42 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_charcmp(char c, char const *set)
{
	int	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (set[j] == c)
			return (1);
		else
			j++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		r;
	char	*result;

	start = 0;
	end = ft_strlen(s1);
	r = 0;
	while (s1[start] != '\0' && ft_charcmp(s1[start], set) == 1)
		start++;
	while (end > start && ft_charcmp(s1[end - 1], set) == 1)
		end--;
	result = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!result)
		return (NULL);
	while (start < end)
	{
		result[r] = s1[start];
		start++;
		r++;
	}
	result[r] = '\0';
	return (result);
}
