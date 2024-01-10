/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:15:02 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/10 16:55:24 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int		finding_enter(char *buffer);
int		gnl_strlen(char *str);
char	*gnl_strjoin(char *s1, char *s2);
char	*reading_buffer(int fd, char *storage);
char	*extract_line(char *storage);
char	*cleaning_storage(char *storage);
char	*get_next_line(int fd);

#endif
