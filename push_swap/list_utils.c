/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:52:04 by username          #+#    #+#             */
/*   Updated: 2026/04/09 16:03:35 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_create_node(int number)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
	{
		return (NULL);
	}
	node->number = number;
	node->lis = 1;
	node->in_lis = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*last;

	if (!list || !new)
	{
		return ;
	}
	new->next = NULL;
	if (!(*list))
	{
		*list = new;
		new->prev = NULL;
		return ;
	}
	last = *list;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;
}

void	ft_lstadd_front(t_list **list, t_list *new)
{
	if (!list || !new)
	{
		return ;
	}
	new->prev = NULL;
	new->next = *list;
	if (*list)
		(*list)->prev = new;
	*list = new;
}

int	list_size(t_list *list)
{
	t_list	*temp;
	int		size;

	temp = list;
	size = 0;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
	{
		return (NULL);
	}
	temp = lst;
	while (temp)
	{
		if (temp->next == NULL || temp->next == lst)
		{
			return (temp);
		}
		temp = temp->next;
	}
	return (NULL);
}
