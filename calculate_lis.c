#include "push_swap.h"

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
            if (prev->index < current->index && current->lis < prev->lis + 1)
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

t_list  *calculate_lis_start(t_list *a, t_list *lis_end)
{
    t_list *temp;
    t_list *lis_start;

    int index = lis_end->lis;

    temp = lis_end;
    while (index > 0 && temp)
    {
        if (index == temp->lis)
        {
            index--;
            temp->in_lis = 1;
            lis_start = temp;
        }
        temp = temp->prev;
    }
    return (lis_start);
}

int    keep_lis_in_a(t_list **a, t_list **b)
{
    int size = list_size(*a);
    int index = 0;
    int n_mov = 0;

    while (index < size)
    {
        if ((*a)->in_lis == 0)
        {
            pb(a, b);
        }
        else
        {
            ra(a, NULL);
        } 
        n_mov++;
        index++;
    }
    return (n_mov);
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
        current->index = index;
        *list = (*list)->next;
        current = *list;
    }
    *list = temp;
}