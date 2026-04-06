#include "push_swap.h"

void    keep_lis_in_a(t_list **a, t_list **b, int *n_mov)
{
    int size;
    int index;

    size = list_size(*a);
    index = 0;
    while (index < size)
    {
        if ((*a)->in_lis == 0)
        {
            pb(a, b, n_mov);
        }
        else
        {
            ra(a, n_mov);
        } 
        index++;
    }
}

void    apply_index(t_list **list)
{
    t_list  *temp;
    t_list  *temp_list;
    t_list  *current;
    int index;

    temp = *list;  
    current = *list;  
    while (*list != NULL)
    { 
        index = 0;
        temp_list = temp;
        while (temp_list != NULL)
        {
            if (temp_list->number < current->number)
            {
                index++;
            }
            temp_list = temp_list->next;
        }
        current->idx = index;
        *list = (*list)->next;
        current = *list;
    }
    *list = temp;
}

t_list *calculate_lis_end(t_list *a)
{
    t_list *current;
    t_list *prev;
    t_list *lis_end;
    int max_len = 0;

    current = a;
    while (current)
    {
        prev = current->prev;
        while (prev)
        {
            if (prev->idx < current->idx && current->lis < prev->lis + 1)
            {
                current->lis = prev->lis + 1;
            }
            prev = prev->prev;
        }
        if (current->lis > max_len)
        {
            max_len = current->lis;
            lis_end = current;  // al final podemos reconstruir el LIS desde aquí
        }
        current = current->next;
    }
    return (lis_end);
}