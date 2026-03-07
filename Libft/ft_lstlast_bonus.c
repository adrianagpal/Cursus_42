/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:28:29 by adrianag          #+#    #+#             */
/*   Updated: 2025/12/03 20:41:26 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
	{
		return (NULL);
	}
	temp = lst;
	while (temp != NULL)
	{
		if (temp->next == NULL || temp->next == lst)
		{
			return (temp);
		}
		temp = temp->next;
	}
	return (NULL);
}
