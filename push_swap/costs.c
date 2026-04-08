#include "push_swap.h"

/* 
cost_b calculates the minimum number of moves needed to place a node at the top of
the stack B. Returns positive for rotations up (rb) and negative for rotations down (rrb). 
*/
int    cost_b(t_list *b, t_list *node)
{
    t_list *temp;
    int size;
    int cost_rb;
    int cost_rrb;

    temp = b;
    size = list_size(b);
    cost_rb = 0;
    cost_rrb = 0;
    while (temp && temp != node)
    {
        cost_rb++;
        temp = temp->next;
    }
    if (!temp)
        return (0);
    cost_rrb = size - cost_rb;
    if (cost_rb > cost_rrb)
        return (-cost_rrb);
    else
        return (cost_rb);
}

/*
cost_a calculates minimum number of moves to insert a node into stack A in order.
Returns positive for rotations up (ra) and negative for rotations down (rra).
*/
int cost_a(t_list *a, t_list *node)
{
    t_list *tmp;
    t_list *prv;
    int cost_ra;
    int cost_rra;

    if (!a)
        return (0);
    cost_ra = 0;
    tmp = a;
    prv = ft_lstlast(a);
    while (tmp)
    {
        if (prv->idx < node->idx && node->idx < tmp->idx)
            break;
        if (prv->idx > tmp->idx && (node->idx > prv->idx || node->idx < tmp->idx))
            break;
        cost_ra++;
        prv = tmp;
        tmp = tmp->next;
    }
    cost_rra = list_size(a) - cost_ra;
    if (cost_ra > cost_rra)
        return (-cost_rra);
    else
        return (cost_ra);
}

/*
calculate_costs calculates cost_a and cost_b for each node in a list. 
*/
void    calculate_costs(t_list *a, t_list *b)
{
    t_list *temp;

    temp = b;
    while (temp)
    {
        temp->cost_a = cost_a(a, temp);
        temp->cost_b = cost_b(b, temp);
        temp = temp->next;
    }
}

/* 
If the sign of the costs is the same, it means both stacks should rotate
in the same direction. Therefore, we count the move as 1. If the sign of the costs
is the opposite, we sum both costs. 
*/
int total_moves(int cost_a, int cost_b)
{
    if ((cost_a >=0 && cost_b >= 0) || (cost_a <=0 && cost_b <= 0))
    {
        return(max(abs(cost_a), abs(cost_b)));
    }
    else
        return(abs(cost_a) + abs(cost_b));
}

t_list  *find_cheapest_node(t_list *b)
{
    t_list *temp;
    t_list *cheapest;
    int total_cost;
    int cheapest_cost;

    temp = b;
    cheapest = b;
    total_cost = 0;
    cheapest_cost = 0;
    while (temp)
    {
        total_cost = total_moves(temp->cost_a, temp->cost_b);
        cheapest_cost = total_moves(cheapest->cost_a, cheapest->cost_b);
        if (total_cost < cheapest_cost)
        {
            cheapest = temp;
        }
        temp = temp->next;
    }
    return (cheapest);
}

