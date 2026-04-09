#include "push_swap.h"

/* 
apply_index assigns an index to each node based on the order in which it should be
in the list. For each node, the function counts how many nodes have a smaller number. 
*/
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

/* 
calculate_lis_end iterates over all nodes, and calculates what is the Longest Increasing
Subsequence (LIS) ending at that node. This value is stored in the lis attribute. 

Return value: It return a pointer to the node that ends the longest increasing subsequence. 
*/
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
            lis_end = current;  
        }
        current = current->next;
    }
    return (lis_end);
}

/* 
calculate_lis_start calculates from the node in which the longest increasing subsquence ends,
which nodes are included in the LIS. It iterates through previous nodes and marks those that 
belong to the LIS updating the value in in_lis to 1. 
*/
t_list  *calculate_lis_start(t_list *lis_end)
{
    t_list *temp;
    t_list *lis_start;
    int index;

    index = lis_end->lis;
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

/* 
keep_lis_in_a moves elements from stack A to stack B, keeping the LIS
(Longest Increasing Subsequence) in A. If the element is not part of the LIS
(in_lis == 0), it is pushed to stack B using pb(). If the element is in the LIS,
the stack A is rotated using ra(). 
*/
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