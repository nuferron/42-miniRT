/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 00:55:18 by nuferron          #+#    #+#             */
/*   Updated: 2024/01/09 22:07:51 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*tmp;
	int		i;

	if (!lst)
		return ;
	i = 1;
	aux = *lst;
	while (aux)
	{
		del(aux->content);
		tmp = aux->next;
		free(aux);
		aux = tmp;
	}
	*lst = NULL;
}
