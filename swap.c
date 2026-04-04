#include "push_swap.h"

void    swap(t_list **list)
{
    t_list  *first;
    t_list  *second;

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

void    sa(t_list **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void    sb(t_list **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void    ss(t_list **a, t_list **b)
{
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}