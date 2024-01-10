/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:14:52 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/10 16:54:05 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*true_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

char	*reading_buffer(int fd, char *storage)
{
	char	*buffer;
	int		r_protection;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (true_free(&storage));
	buffer[0] = '\0';
	r_protection = 1;
	while (finding_enter(buffer) == -1 && r_protection != 0)
	{
		r_protection = read(fd, buffer, BUFFER_SIZE);
		if (r_protection == -1)
		{
			free(storage);
			free(buffer);
			return (NULL);
		}
		buffer[r_protection] = '\0';
		if (r_protection > 0)
			storage = gnl_strjoin(storage, buffer);
		if (storage == NULL)
			return (true_free(&buffer));
	}
	free(buffer);
	return (storage);
}

char	*extract_line(char *storage)
{
	char	*line;
	int		enter;

	enter = 0;
	if (storage[0] == '\0')
		return (NULL);
	while (storage[enter] != '\n' && storage[enter] != '\0')
		enter++;
	if (storage[enter] == '\n')
		enter++;
	line = (char *)malloc(sizeof(char) * (enter + 1));
	if (!line)
		return (NULL);
	line[enter--] = '\0';
	while (enter >= 0)
	{
		line[enter] = storage[enter];
		enter--;
	}
	return (line);
}

char	*cleaning_storage(char *storage)
{
	char	*next_storage;
	int		len;
	int		enter;
	int		i;

	i = 0;
	enter = finding_enter(storage);
	if (enter == -1)
	{
		free(storage);
		return (NULL);
	}
	len = gnl_strlen(storage);
	next_storage = (char *)malloc(sizeof(char) * (len - enter + 1));
	if (!next_storage)
	{
		free(storage);
		return (NULL);
	}
	while (storage[enter] != '\0')
		next_storage[i++] = storage[++enter];
	next_storage[i] = '\0';
	free(storage);
	return (next_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (finding_enter(storage) == -1)
		storage = reading_buffer(fd, storage);
	if (!storage)
		return (NULL);
	line = extract_line(storage);
	if (!line)
		return (true_free(&storage));
	storage = cleaning_storage(storage);
	return (line);
}
