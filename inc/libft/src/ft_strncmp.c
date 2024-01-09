/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 17:04:51 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/09 22:07:00 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
		{
			if (s1[i] == s2[i])
				i++;
			else
				return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		}
	}
	return (0);
}
