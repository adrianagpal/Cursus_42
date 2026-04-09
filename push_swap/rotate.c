/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:52:43 by username          #+#    #+#             */
/*   Updated: 2026/04/09 16:03:57 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a, int *n_mov)
{
	t_list	*temp;

	temp = *a;
	*a = (*a)->next;
	ft_lstadd_back(a, temp);
	write(1, "ra\n", 3);
	(*n_mov)++;
}

void	rb(t_list **b, int *n_mov)
{
	t_list	*temp;

	temp = *b;
	*b = (*b)->next;
	ft_lstadd_back(b, temp);
	write(1, "rb\n", 3);
	(*n_mov)++;
}

void	rr(t_list **a, t_list **b, int *n_mov)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = *a;
	temp_b = *b;
	*a = (*a)->next;
	*b = (*b)->next;
	ft_lstadd_back(a, temp_a);
	ft_lstadd_back(b, temp_b);
	write(1, "rr\n", 3);
	(*n_mov)++;
}
