#include "push_swap.h"

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

int max_index(t_list *list)
{
    int max;
    t_list *temp;

    if (!list)
        return -1; // lista vacía, devuelvo -1 como indicador
    max = list->idx;
    temp = list;
    while (temp)
    {
        if (temp->idx > max)
            max = temp->idx;
        temp = temp->next;
    }
    return (max);
}

int min_index(t_list *list)
{
    int min;
    t_list *temp;

    if (!list)
        return -1; // lista vacía, devuelvo -1 como indicador
    min = list->idx;
    temp = list;
    while (temp)
    {
        if (temp->idx < min)
            min = temp->idx;
        temp = temp->next;
    }
    return (min);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
	{
		return (NULL);
	}
	temp = lst;
	while (temp != NULL)
	{
		if (temp->next == NULL || temp->next == lst)
		{
			return (temp);
		}
		temp = temp->next;
	}
	return (NULL);
}

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

void    apply_costs(t_list *a, t_list *b)
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