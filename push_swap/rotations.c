/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:52:48 by username          #+#    #+#             */
/*   Updated: 2026/04/09 16:04:02 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_list **a, t_list **b, t_list *node, int *n_mov)
{
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		rr(a, b, n_mov);
		node->cost_a--;
		node->cost_b--;
	}
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		rrr(a, b, n_mov);
		node->cost_a++;
		node->cost_b++;
	}
}

void	rotate_single(t_list **a, t_list **b, t_list *node, int *n_mov)
{
	while (node->cost_a > 0)
	{
		ra(a, n_mov);
		node->cost_a--;
	}
	while (node->cost_a < 0)
	{
		rra(a, n_mov);
		node->cost_a++;
	}
	while (node->cost_b > 0)
	{
		rb(b, n_mov);
		node->cost_b--;
	}
	while (node->cost_b < 0)
	{
		rrb(b, n_mov);
		node->cost_b++;
	}
}

void	apply_rotations(t_list **a, t_list **b, t_list *node, int *n_mov)
{
	rotate_both(a, b, node, n_mov);
	rotate_single(a, b, node, n_mov);
	pa(a, b, n_mov);
}

/*
reinsertion calculates the costs for each node in the list, finds the node that
requires less moves to be inserted in order in stack A and apply required
rotations to do it.
*/

void	reinsertion(t_list **a, t_list **b, int *n_mov)
{
	t_list	*node;

	while (*b)
	{
		calculate_costs(*a, *b);
		node = find_cheapest_node(*b);
		apply_rotations(a, b, node, n_mov);
	}
}

/*
Once the list is ordered, but the lowest index is not in the first position,
this function returns the lowest index back to the top of the stack.
*/

void	return_a_to_origin(t_list **a, int *n_mov)
{
	t_list	*temp;
	int		cost_ra;
	int		cost_rra;

	temp = *a;
	cost_ra = 0;
	cost_rra = 0;
	while (temp && temp->idx != 0)
	{
		cost_ra++;
		temp = temp->next;
	}
	cost_rra = list_size(*a) - cost_ra;
	if (cost_ra <= cost_rra)
	{
		while (cost_ra-- > 0)
			ra(a, n_mov);
	}
	else
	{
		while (cost_rra-- > 0)
			rra(a, n_mov);
	}
}
