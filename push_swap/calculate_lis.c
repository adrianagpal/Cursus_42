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