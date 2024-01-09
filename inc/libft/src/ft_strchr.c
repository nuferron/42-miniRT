/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:54:46 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 20:21:42 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*bookmark;
	int		i;
	char	*aux_s;

	aux_s = (char *) s;
	i = 0;
	while (aux_s[i] != '\0' && aux_s[i] != (unsigned char)c)
		i++;
	if ((unsigned char)c != '\0' && aux_s[i] == '\0')
		bookmark = NULL;
	else
		bookmark = &aux_s[i];
	return (bookmark);
}
