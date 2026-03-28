#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_list
{
    int number;
    struct s_list   *next;
    struct s_list   *prev;
}   t_list;

int	ft_atoi(const char *nptr)
{
	int	result;
	int	index;
	int	sign;

	result = 0;
	index = 0;
	sign = 1;
	while (nptr[index] == ' ' || (nptr[index] >= 9 && nptr[index] <= 13))
	{
		index++;
	}
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
		{
			sign = -1 * sign;
		}
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result = result * 10 + (nptr[index] - '0');
		index++;
	}
	return (sign * result);
}

t_list  *ft_create_node(int number)
{
    t_list  *node;
    node = malloc(sizeof(t_list));
    if (!node)
    {
        return (NULL);
    }
    node->number = number;
    node->next = node;
    node->prev = node;
    return (node);
}

void    ft_lstadd_back(t_list **list, t_list *new)
{
    if (!list || !new)
    {
        return ;
    }
    if (!(*list))
    {
        *list = new;
        new->next = new;
        new->prev = new;
        return ;
    }
    new->prev = (*list)->prev;
    new->next = *list;
    (*list)->prev->next = new;
    (*list)->prev = new;
}

void    ft_lstadd_front(t_list **list, t_list *new)
{
    ft_lstadd_back(list, new);
    *list = new;
}

void    swap(t_list **list)
{
    t_list *mem_next;
    t_list *mem_prev;

    if (!list)
        return ;
    mem_next = (*list)->next->next;
    mem_prev = (*list)->next;
    (*list)->prev->next = (*list)->next;
    (*list)->next->prev = (*list)->prev;
    (*list)->next->next = *list;
    (*list)->prev = mem_prev;
    (*list)->next = mem_next;    
    *list = mem_prev;
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

void    push(t_list **a, t_list **b)
{
    t_list  *node;
    if (!(*b) || !b)
    {
        return ;
    }
    node = *b;

    (*b)->prev->next = (*b)->next;
    (*b)->next->prev = (*b)->prev;
    *b = (*b)->next;

    ft_lstadd_front(a, node);
}

void    pa(t_list **a, t_list **b)
{
    push(a, b);
    write(1, "pa\n", 3);
}

void    pb(t_list **a, t_list **b)
{
    push(b, a);
    write(1, "pb\n", 3);
}

void    ra(t_list **a)
{
    *a = (*a)->next;    
    write(1, "ra\n", 3);
}

void    rb(t_list **b)
{
    *b = (*b)->next;    
    write(1, "rb\n", 3);
}

void    rr(t_list **a, t_list **b)
{
    *a = (*a)->next; 
    *b = (*b)->next;    
    write(1, "rr\n", 3);
}

void    rra(t_list **a)
{
    *a = (*a)->prev;    
    write(1, "rra\n", 4);
}

void    rrb(t_list **b)
{
    *b = (*b)->prev;    
    write(1, "rrb\n", 4);
}

void    rrr(t_list **a, t_list **b)
{
    *a = (*a)->prev; 
    *b = (*b)->prev;    
    write(1, "rrr\n", 4);
}

double compute_disorder(t_list **a)
{
    int mistakes;
    int total_pairs;
    t_list  *temp;

    if (!a || !(*a) || (*a)->next == *a)
        return (0);

    total_pairs = 0;
    mistakes = 0;
    temp = *a;
    while (temp->next != *a)
    {
        total_pairs += 1;
        if (temp->number > temp->next->number)
        {
            mistakes += 1;
        }
        temp = temp->next;
    }    
    printf("mistakes: %d\n", mistakes);
    printf("pairs: %d\n", total_pairs);
    return (1 - (double)mistakes / (double)total_pairs);
}

int main(int argc, char **argv)
{
    int index;
    t_list  *list = NULL;
    t_list  *list2 = NULL;
    t_list  *node;

    index = 0;
    if (argc < 2)
    {
        printf("Error");
        return (1);
    }
    while (index < argc - 1)
    {
        /*printf("%d", ft_atoi(argv[index + 1]));*/
        node = ft_create_node(ft_atoi(argv[index + 1]));
        ft_lstadd_back(&list, node);
        index++;
    }
    
    printf("%d\n", list->number);
    printf("%d\n", list->next->number);
    printf("%d\n", list->next->next->number);
 
    double desorden = compute_disorder(&list);
    printf("%f\n", desorden);


    return (0);

}