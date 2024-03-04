/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:57:27 by nuferron          #+#    #+#             */
/*   Updated: 2024/03/04 17:19:04 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*It skips whitespaces*/
int	skip_space(char *line, int *i)
{
	while (line[*i] && is_whitespace(line[*i]))
		(*i)++;
	return (0);
}

/*It skips number including floats*/
int	skip_number(char *line, int *i)
{
	if (line[*i] == '-')
		(*i)++;
	while (line[*i] && ft_isdigit(line[*i]))
	{
		(*i)++;
		if (line[*i] == '.')
			(*i)++;
	}
	return (0);
}

void	skip_sp_num_sp(char *line, int *i)
{
	skip_space(line, i);
	skip_number(line, i);
	skip_space(line, i);
}

t_item	*item_lstlast(t_item *lst)
{
	if (!lst)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
