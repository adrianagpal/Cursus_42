#include "push_swap.h"

void    push(t_list **a, t_list **b)
{
    t_list  *node;

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

void    pa(t_list **a, t_list **b, int *n_mov)
{
    push(a, b);
    write(1, "pa\n", 3);
    (*n_mov)++;
}

void    pb(t_list **a, t_list **b, int *n_mov)
{
    push(b, a);
    write(1, "pb\n", 3);
    (*n_mov)++;
}