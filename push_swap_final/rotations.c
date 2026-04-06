#include "push_swap.h"

void rotate_both(t_list **a, t_list **b, t_list *node, int *n_mov)
{
    while (node->cost_a > 0 && node->cost_b > 0)
    {
        rr(a, b, n_mov);
        node->cost_a--;
        node->cost_b--;
    }
    while (node->cost_a < 0 && node->cost_b < 0)
    {
        rrr(a, b, n_mov);
        node->cost_a++;
        node->cost_b++;
    }
}

void rotate_single(t_list **a, t_list **b, t_list *node, int *n_mov)
{
    while (node->cost_a > 0)
    {
        ra(a, n_mov);
        node->cost_a--;
    }
    while (node->cost_a < 0)
    {
        rra(a, n_mov);
        node->cost_a++;
    }
    while (node->cost_b > 0)
    {
        rb(b, n_mov);
        node->cost_b--;
    }
    while (node->cost_b < 0)
    {
        rrb(b, n_mov);
        node->cost_b++;
    }
}

void apply_rotations(t_list **a, t_list **b, t_list *node, int *n_mov)
{
    rotate_both(a, b, node, n_mov);
    rotate_single(a, b, node, n_mov);
    pa(a, b, n_mov);
}

void    reinsertion(t_list **a, t_list **b, int *n_mov)
{
    t_list  *node;

    while (*b)
    {
        apply_costs(*a, *b);                  // actualizar costes
        node = find_cheapest_node(*b);   // nodo más barato
        apply_rotations(a, b, node, n_mov);        // mover nodo y push a A
    }
}

void    return_a_to_origin(t_list **a, t_list **b, int *n_mov)
{
    t_list *temp;
    int cost_ra;
    int cost_rra;

    temp = *a;
    cost_ra = 0;
    cost_rra = 0;
    while (temp && temp->idx != 0)
    {
        cost_ra++;
        temp = temp->next;
    }
    cost_rra = list_size(*a) - cost_ra;
    if (cost_ra <= cost_rra)
    {
        while(cost_ra-- > 0)
        {
            ra(a, n_mov);
        }    
    }
    else
    {
        while(cost_rra-- > 0)
        {
            rra(a, n_mov);
        }      
    }
}