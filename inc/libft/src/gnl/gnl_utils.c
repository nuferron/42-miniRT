/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:15:13 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/10 16:54:45 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	finding_enter(char *buffer)
{
	int	enter;

	if (buffer == NULL)
		return (-1);
	enter = 0;
	while (buffer[enter] != '\n' && buffer[enter] != '\0')
		enter++;
	if (buffer[enter] == '\0')
		return (-1);
	return (enter);
}

int	gnl_strlen(char *str)
{
	int	counter;

	counter = 0;
	if (str == NULL)
		return (0);
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

char	*gnl_strjoin(char *storage, char *buffer)
{
	int		tlen;
	int		i;
	char	*new_storage;

	i = 0;
	tlen = gnl_strlen(storage) + gnl_strlen(buffer);
	new_storage = (char *) malloc(sizeof(char) * (tlen + 1));
	if (!new_storage)
	{
		free(storage);
		return (NULL);
	}
	while (storage && storage[i] != '\0')
	{
		new_storage[i] = storage[i];
		i++;
	}
	while (buffer && i <= tlen)
	{
		new_storage[tlen] = buffer[tlen - i];
		tlen--;
	}
	free(storage);
	return (new_storage);
}
