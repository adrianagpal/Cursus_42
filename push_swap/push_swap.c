/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:52:22 by username          #+#    #+#             */
/*   Updated: 2026/04/09 18:52:21 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *list)
{
	t_list	*temp;

	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
}

void	push_swap_small(t_list **a, int *n_mov)
{
	t_list	*last;

	last = ft_lstlast(*a);
	if ((*a)->idx > (*a)->next->idx && (*a)->idx < last->idx)
		sa(a, n_mov);
	else if ((*a)->idx < (*a)->next->idx && (*a)->idx > last->idx)
		rra(a, n_mov);
	else if ((*a)->idx > (*a)->next->idx && (*a)->idx > last->idx)
	{
		if ((*a)->next->idx < last->idx)
			ra(a, n_mov);
		else
		{
			sa(a, n_mov);
			rra(a, n_mov);
		}
	}
	else if ((*a)->idx < (*a)->next->idx && (*a)->idx < last->idx)
	{
		if ((*a)->next->idx > last->idx)
		{
			sa(a, n_mov);
			ra(a, n_mov);
		}
	}
}

void	push_swap_10(t_list **a, t_list **b, int *n_mov)
{
	int	idx_limit;

	idx_limit = list_size(*a) - 3;
	while (list_size(*a) > 3)
	{
		if ((*a)->idx < idx_limit)
			pb(a, b, n_mov);
		else
			ra(a, n_mov);
	}
	push_swap_small(a, n_mov);
	while (*b)
		reinsertion(a, b, n_mov);
	return_a_to_origin(a, n_mov);
}

void	push_swap(t_list *a)
{
	int		n_mov;
	t_list	*b;
	t_list	*lis_end;

	b = NULL;
	n_mov = 0;
	apply_index(&a);
	if (check_ordered(a) == TRUE)
		return ;
	if (list_size(a) == 2)
	{
		if (a->idx > a->next->idx)
			sa(&a, &n_mov);
		return ;
	}
	if (list_size(a) >= 3 && list_size(a) <= 10)
	{
		push_swap_10(&a, &b, &n_mov);
		return ;
	}
	lis_end = calculate_lis_end(a);
	calculate_lis_start(lis_end);
	keep_lis_in_a(&a, &b, &n_mov);
	reinsertion(&a, &b, &n_mov);
	return_a_to_origin(&a, &n_mov);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	char	*new_argv;

	if (argc == 1)
		return (0);
	if (check_valid(argv, argc) == FALSE)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	new_argv = join_arguments(argv, argc);
	a = NULL;
	if (load_list(&a, new_argv) == FALSE || check_duplicates(a) == TRUE)
	{
		write(2, "Error\n", 6);
		free(new_argv);
		free_list(a);
		exit(EXIT_FAILURE);
	}
	if (list_size(a) > 1)
		push_swap(a);
	free(new_argv);
	free_list(a);
	return (0);
}
