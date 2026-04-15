/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:52:53 by username          #+#    #+#             */
/*   Updated: 2026/04/15 17:34:34 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list)
{
	t_list	*first;
	t_list	*second;

	if (!list || !(*list) || !(*list)->next)
		return ;
	first = *list;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*list = second;
}

void	sa(t_list **a, int *n_mov)
{
	swap(a);
	write(1, "sa\n", 3);
	(*n_mov)++;
}

void	sb(t_list **b, int *n_mov)
{
	swap(b);
	write(1, "sb\n", 3);
	(*n_mov)++;
}

void	ss(t_list **a, t_list **b, int *n_mov)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	(*n_mov)++;
}

t_bool	ft_is_digit_sign(char c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == '+')
		return (TRUE);
	return (FALSE);
}
