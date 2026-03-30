#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef enum
{
    FALSE,
    TRUE
} t_bool;

typedef struct s_list
{
    int number;
    double index;
    struct s_list   *next;
    struct s_list   *prev;
}   t_list;

int	ft_atoi(const char *nptr)
{
	int result;
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
    node->next = NULL;
    node->prev = NULL;
    return (node);
}

void    ft_lstadd_back(t_list **list, t_list *new)
{
    t_list *last;

    if (!list || !new)
    {
        return ;
    }
    new->next = NULL;
    if (!(*list))
    {
        *list = new;
        new->prev = NULL;
        return ;
    }
    last = *list;
    while (last->next != NULL)
        last = last->next;
    last->next = new;
    new->prev = last;
}

void    ft_lstadd_front(t_list **list, t_list *new)
{
    if (!list || !new)
    {
        return ;
    }
    new->prev = NULL;
    new->next = *list;
    if (*list)
        (*list)->prev = new;
    *list = new;
}

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
    /*write(1, "sa\n", 3);*/
}

void    sb(t_list **b)
{
    swap(b);
    /*write(1, "sb\n", 3);*/
}

void    ss(t_list **a, t_list **b)
{
    swap(a);
    swap(b);
    /*write(1, "ss\n", 3);*/
}

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

void    pa(t_list **a, t_list **b)
{
    push(a, b);
    /*write(1, "pa\n", 3);*/
}

void    pb(t_list **a, t_list **b)
{
    push(b, a);
    /*write(1, "pb\n", 3);*/
}

void    ra(t_list **a)
{
    *a = (*a)->next;    
    /*write(1, "ra\n", 3);*/
}

void    rb(t_list **b)
{
    *b = (*b)->next;    
    /*write(1, "rb\n", 3);*/
}

void    rr(t_list **a, t_list **b)
{
    *a = (*a)->next; 
    *b = (*b)->next;    
    /*write(1, "rr\n", 3);*/
}

void    rra(t_list **a)
{
    *a = (*a)->prev;    
    /*write(1, "rra\n", 4);*/
}

void    rrb(t_list **b)
{
    *b = (*b)->prev;    
    /*write(1, "rrb\n", 4);*/
}

void    rrr(t_list **a, t_list **b)
{
    *a = (*a)->prev; 
    *b = (*b)->prev;    
    /*write(1, "rrr\n", 4);*/
}

/* CHECK ERRORS */
static int  is_valid_number(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (str[i] == '\0')
        return (0);
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

static int  has_duplicate(t_list *list, int number)
{
    while (list != NULL)
    {
        if (list->number == number)
            return (1);
        list = list->next;
    }
    return (0);
}

void    load_list(t_list **list, char **argv, int argc)
{
    int     index;
    int     number;
    t_list  *node;

    index = 1;
    while (index < argc)
    {
        if (!is_valid_number(argv[index]))
        {
            // manejar error
            return ;
        }
        number = ft_atoi(argv[index]);
        if (has_duplicate(*list, number))
        {
            // manejar error
            return ;
        }
        node = ft_create_node(number);
        if (!node)
            return ;
        ft_lstadd_back(list, node);
        index++;
    }
}

void check_min_max(t_list **list, double *max, double *min, int *len)
{
    t_list  *temp;

    if (!list || !*list)
    {
        *len = 0;
        return;
    }

    *max = (*list)->number;
    *min = (*list)->number;
    *len = 1;
    temp = (*list)->next;
    while (temp != *list)
    {
        if (temp->number > *max)
        {
            *max = temp->number;
        }
        if (temp->number < *min)
        {
            *min = temp->number;
        }
        temp = temp->next;
        (*len)++;
    }
}

void    get_disordered_out(t_list **a, t_list **b)
{
    pb(a, b);
    write(1, "pb\n", 3);
    while (*a != NULL)
    {
        if ((*a)->number > (*a)->next->number)
        {
            pb(a, b);
            write(1, "pb\n", 3);
        }
        else
        {
            ra(a);
            write(1, "ra\n", 3);
        }
    }
}

void    put_them_back(t_list **a, t_list **b)
{
    if (!b || !*b)
        return;
    while (*b)
    {
        if ((*b)->index > (*a)->prev->index && (*b)->index < (*a)->index)
        {
            pa(a, b);
        }
        else
        {
            rb(b);
        }
    }
}

int main(int argc, char **argv)
{
    int index;
    t_list  *list = NULL;
    t_list  *list2 = NULL;
    t_list  *list3 = NULL;
    t_list  *node;
    int disorder = 0;

    index = 0;
    if (argc < 2)
    {
        char *debug_argv[] = {"push_swap", "10 2 4 7 9 8 3 5 12 20 1 6 45 32 33 98 76", "5"};
        argc = 2;
        argv = debug_argv;
    }
    load_list(&list, argv, argc);
    
    printf("This is chaos:%d\n", disorder);
    /*int valid = check_valid(argv, argc);
    printf("%d\n", valid);*/

    printf("%d\n", list->number);
    printf("%d\n", list->next->number);
    printf("%d\n", list->next->next->number);
    printf("%d\n", list->next->next->next->number);
    printf("%d\n", list->next->next->next->next->number);

    /*int check = check_duplicates(list);
    printf("Duplicates:%d\n", check);
    printf("Inversions:%d\n", inv);*/

    /*int n_mov = check_maximum(&list, &list3);*/

    /*printf("Number of movements: %d\n", n_mov);*/

    get_disordered_out(&list, &list3);
    //put_them_back(&list, &list3);

    printf("New list:\n%d\n", list->number);
    printf("%d\n", list->next->number);
    printf("%d\n", list->next->next->number);
    printf("%d\n", list->next->next->next->number);
    printf("%d\n", list->next->next->next->next->number);
    printf("%d\n", list->next->next->next->next->next->number);
    printf("%d\n", list->next->next->next->next->next->next->number);
    printf("%d\n", list->next->next->next->next->next->next->next->number);

    printf("Second list:\n%d\n", list3->number);
    printf("%d\n", list3->next->number);
    printf("%d\n", list3->next->next->number);
    printf("%d\n", list3->next->next->next->number);
    printf("%d\n", list3->next->next->next->next->number);
    printf("%d\n", list3->next->next->next->next->next->number);
    printf("%d\n", list3->next->next->next->next->next->next->number);
    printf("%d\n", list3->next->next->next->next->next->next->next->number);

    return (0);
}
