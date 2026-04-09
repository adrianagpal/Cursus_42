/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:52:39 by username          #+#    #+#             */
/*   Updated: 2026/04/09 16:03:54 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a, int *n_mov)
{
	t_list	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	last = ft_lstlast(*a);
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = *a;
	(*a)->prev = last;
	*a = last;
	write(1, "rra\n", 4);
	(*n_mov)++;
}

void	rrb(t_list **b, int *n_mov)
{
	t_list	*last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	last = ft_lstlast(*b);
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = *b;
	(*b)->prev = last;
	*b = last;
	write(1, "rrb\n", 4);
	(*n_mov)++;
}

void	rra_no_print(t_list **a)
{
	t_list	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	last = ft_lstlast(*a);
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = *a;
	(*a)->prev = last;
	*a = last;
}

void	rrb_no_print(t_list **b)
{
	t_list	*last;

	if (!b || !(*b) || !(*b)->next)
		return ;
	last = ft_lstlast(*b);
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = *b;
	(*b)->prev = last;
	*b = last;
}

void	rrr(t_list **a, t_list **b, int *n_mov)
{
	rra_no_print(a);
	rrb_no_print(b);
	write(1, "rrr\n", 4);
	(*n_mov)++;
}
