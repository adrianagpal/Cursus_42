/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:52:33 by username          #+#    #+#             */
/*   Updated: 2026/04/09 16:03:51 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **a, t_list **b)
{
	t_list	*node;

	if (!b || !(*b))
		return ;
	node = *b;
	*b = node->next;
	if (*b)
		(*b)->prev = NULL;
	node->next = NULL;
	node->prev = NULL;
	ft_lstadd_front(a, node);
}

void	pa(t_list **a, t_list **b, int *n_mov)
{
	push(a, b);
	write(1, "pa\n", 3);
	(*n_mov)++;
}

void	pb(t_list **a, t_list **b, int *n_mov)
{
	push(b, a);
	write(1, "pb\n", 3);
	(*n_mov)++;
}
