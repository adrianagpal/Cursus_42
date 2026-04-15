/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:52:28 by username          #+#    #+#             */
/*   Updated: 2026/04/15 17:34:23 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_list
{
	int				number;
	int				idx;
	int				lis;
	int				in_lis;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

/* PARSING (parsing.c) */
t_bool	check_valid(char **argv, int argc);
char	*join_arguments(char **argv, int argc);
t_bool	load_list(t_list **list, char *nw_arg);
t_bool	valid_atoi(const char *nptr, int *nbr);
t_bool	check_duplicates(t_list *list);

/* LIST UTILS (list_utils.c) */
t_list	*ft_create_node(int number);
void	ft_lstadd_back(t_list **list, t_list *new);
void	ft_lstadd_front(t_list **list, t_list *new);
int		list_size(t_list *list);
t_list	*ft_lstlast(t_list *lst);

/* LIBFT UTILS (libft_utils.c) */
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_realloc(char *ptr, size_t size, int n_char);
int		ft_strlen(char *str);
int		abs(int n);
int		max(int a, int b);

/* CALCULATE LIS (calculate_lis.c) */
void	apply_index(t_list **list);
t_list	*calculate_lis_end(t_list *a);
t_list	*calculate_lis_start(t_list *lis_end);
void	keep_lis_in_a(t_list **a, t_list **b, int *n_mov);
t_bool	check_ordered(t_list *a);

/* CALCULATE COSTS (costs.c) */
int		cost_b(t_list *b, t_list *node);
int		cost_a(t_list *a, t_list *nod);
void	calculate_costs(t_list *a, t_list *b);
int		total_moves(int cost_a, int cost_b);
t_list	*find_cheapest_node(t_list *b);

/* ROTATIONS (rotations.c) */
void	rotate_both(t_list **a, t_list **b, t_list *node, int *n_mov);
void	rotate_single(t_list **a, t_list **b, t_list *node, int *n_mov);
void	apply_rotations(t_list **a, t_list **b, t_list *node, int *n_mov);
void	reinsertion(t_list **a, t_list **b, int *n_mov);
void	return_a_to_origin(t_list **a, int *n_mov);

/* SWAP (swap.c) */
void	swap(t_list **list);
void	sa(t_list **a, int *n_mov);
void	sb(t_list **b, int *n_mov);
void	ss(t_list **a, t_list **b, int *n_mov);
t_bool	ft_is_digit_sign(char c);

/* PUSH (push.c) */
void	push(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b, int *n_mov);
void	pb(t_list **a, t_list **b, int *n_mov);

/* ROTATE (rotate.c) */
void	ra(t_list **a, int *n_mov);
void	rb(t_list **a, int *n_mov);
void	rr(t_list **a, t_list **b, int *n_mov);

/* REVERSE ROTATE (reverse_rotate.c) */
void	rra(t_list **a, int *n_mov);
void	rrb(t_list **b, int *n_mov);
void	rra_no_print(t_list **a);
void	rrb_no_print(t_list **b);
void	rrr(t_list **a, t_list **b, int *n_mov);

#endif
