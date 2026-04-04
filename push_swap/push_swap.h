#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef enum
{
    FALSE,
    TRUE
} t_bool;

typedef struct s_list
{
    int number;
    int idx;
    int lis;
    int in_lis;
    int cost_a;
    int cost_b;
    struct s_list   *lis_start;
    struct s_list   *next;
    struct s_list   *prev;
}   t_list;

/* PARSING */
int check_valid(char **argv, int argc);
int check_duplicates(t_list *list);
char *join_arguments(char **argv, int argc);
int    valid_atoi(const char *nptr, int *nbr);
int    load_list(t_list **list, char *new_argv);

/* LIST UTILS */
t_list  *ft_create_node(int number);
void    ft_lstadd_back(t_list **list, t_list *new);
void    ft_lstadd_front(t_list **list, t_list *new);
int    list_size(t_list *list);
void free_list(t_list *list);

/* LIBFT UTILS */
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_realloc(char *ptr, size_t size, int n_char);
int ft_strlen(char *str);
int abs(int n);
int max(int a, int b) ;

/* CALCULATE LIS */
void    keep_lis_in_a(t_list **a, t_list **b, int *n_mov);
void    apply_index(t_list **list);

/* CALCULATE COSTS */
int    cost_b(t_list *b, t_list *node);
int    cost_a(t_list *a, t_list *node);
void    apply_costs(t_list *a, t_list *b);
int total_moves(int cost_a, int cost_b);
t_list  *find_cheapest_node(t_list *b);

/* ROTATIONS */
void rotate_both(t_list **a, t_list **b, t_list *node, int *n_mov);
void rotate_single(t_list **a, t_list **b, t_list *node, int *n_mov);
void apply_rotations(t_list **a, t_list **b, t_list *node, int *n_mov);
void    reinsertion(t_list **a, t_list **b, int *n_mov);
void    return_a_to_origin(t_list **a, t_list **b, int *n_mov);

/* SWAP */
void    swap(t_list **list);
void    sa(t_list **a, int *n_mov);
void    sb(t_list **b, int *n_mov);
void    ss(t_list **a, t_list **b, int *n_mov);

/* PUSH */
void    push(t_list **a, t_list **b);
void    pa(t_list **a, t_list **b, int *n_mov);
void    pb(t_list **a, t_list **b, int *n_mov);

/* ROTATE */
void    ra(t_list **a, int *n_mov);
void    rb(t_list **a, int *n_mov);
void    rr(t_list **a, t_list **b, int *n_mov);

/* REVERSE ROTATE */
void    rra(t_list **a, int *n_mov);
void rrb(t_list **b, int *n_mov);
void    rra_no_print(t_list **a);
void rrb_no_print(t_list **b);
void    rrr(t_list **a, t_list **b, int *n_mov);

#endif
