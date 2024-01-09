/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 01:50:07 by nuferron          #+#    #+#             */
/*   Updated: 2023/09/13 20:21:41 by nuferron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*last_content;
	t_list	*new_node;
	t_list	*fil;

	fil = NULL;
	while (lst)
	{
		last_content = f(lst->content);
		if (last_content == NULL)
		{
			ft_lstclear(&fil, del);
			return (NULL);
		}
		new_node = ft_lstnew(last_content);
		if (new_node == NULL)
		{
			ft_lstclear(&fil, del);
			free(last_content);
			return (NULL);
		}
		ft_lstadd_back(&fil, new_node);
		lst = lst->next;
	}
	return (fil);
}
