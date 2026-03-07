/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:28:34 by adrianag          #+#    #+#             */
/*   Updated: 2025/12/04 12:19:17 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*node;
	t_list	*new_list;
	void	*new_content;

	if (!lst || lst == NULL || !f || !del)
		return (NULL);
	temp = lst;
	new_list = NULL;
	while (temp != NULL)
	{
		new_content = f(temp->content);
		node = ft_lstnew(new_content);
		if (node == NULL)
		{
			ft_lstclear(&new_list, del);
			del(new_content);
			return (NULL);
		}
		ft_lstadd_back(&new_list, node);
		temp = temp->next;
	}
	return (new_list);
}
