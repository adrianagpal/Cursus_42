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
    {
        return ;
    }
    node = *b;
    if (node->next == node)
    {
        *b = NULL;
        node->next = node->prev = node; 
        ft_lstadd_front(a, node);
        return ;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    *b = node->next;

    node->next = node->prev = node;
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
    /*printf("mistakes: %d\n", mistakes);
    printf("pairs: %d\n", total_pairs);*/
    return (1 - (double)mistakes / (double)total_pairs);
}

/* CHECK ERRORS */
int check_valid(char **argv, int argc)
{
    int index;
    int j;
    char ch;

    index = 0;
    while (index < argc)
    {
        j = 0;
        while ((ch = argv[index + 1][j]) != '\0')
        {
            if (!(ch >= '0' && ch <= '9') && ch != ' ')
                return (FALSE);
            j++;
        }
        index++;
    }
    return (TRUE); 
}

void    load_list(t_list **list, char **argv, int argc)
{
    int index;
    int j;
    int flag;
    t_list  *node = NULL;

    index = 0;
    while (index < argc)
    {
        j = 0;
        flag = 0;
        while (argv[index + 1][j] != '\0')
        {
            /* Falta comprobar si hay signos - seguidos */
            if (((argv[index + 1][j] >= '0' && argv[index + 1][j] <= '9') 
                || argv[index + 1][j] == '-') && flag == 0)
            {
                node = ft_create_node(ft_atoi(&argv[index + 1][j]));
                ft_lstadd_back(list, node);
                flag = 1;
            }
            else if (argv[index + 1][j] == ' ')
                flag = 0;
            j++;
        }
        index++;
    }
}

/* Calculates duplicates and inversions at the same time */
int check_duplicates(t_list *list)
{
    t_list  *current;
    t_list  *temp;
    int inv;

    current = list;
    temp = list->next;
    inv = 0;
    while (current->next != list)
    {
        while (temp != list)
        {
            /*printf("%dy%d:", current->number, temp->number);*/
            if (current->number == temp->number) 
            {
                return (-1);
            }  
            else if (current->number > temp->number) 
            {
                inv++;
            }   
            temp = temp->next;
        }
        current = current->next;
        temp = current->next;
    }
    return (inv);
}

int *check_delta(t_list **a, t_list **b, int *mov)
{
    sa(a);
    mov[0] = check_duplicates(*a);
    sa(a);

    if (*b)
    {   
        pa(a, b);
        mov[1] = check_duplicates(*a);
        pb(a, b);
    }
    /* Pasar primer numero de a a b */
    pb(a, b);
    mov[2] = check_duplicates(*a);
    pa(a, b);

    ra(a);
    mov[3] = check_duplicates(*a);
    rra(a);

    rra(a);
    mov[4] = check_duplicates(*a);
    ra(a);
    return (mov);
}

int best_movement(int *movements)
{
    int index;
    int min;

    index = 0;
    min = 0;
    while (index < 6)
    {
        if (movements[index] < movements[min])
            min = index;
        index++;
    }
    return (min);
}

void    perform_movement(t_list **a, t_list **b)
{
    int best_mov;
    int mov[6];
    static int movimiento;

    best_mov = 0;
    movimiento = 0;
    mov[5] = check_duplicates(*a);
    best_mov = best_movement(check_delta(a, b, mov));
    if (best_mov == movimiento)
    {
        best_mov = 5;
    }
    movimiento = best_mov;
    if (best_mov == 0)
    {
        sa(a);
        write(1, "sa\n", 3);
    }    
    else if (best_mov == 1)
    {
        pa(a, b);
        write(1, "pa\n", 3);
    }  
    else if (best_mov == 2)
    {
        pb(a, b);
        write(1, "pb\n", 3);
    }
    else if (best_mov == 3)
    {
        ra(a);
        write(1, "ra\n", 3);
    }
    else if (best_mov == 4)
    {
        rra(a);
        write(1, "rra\n", 4);
    }
}

void    order_list(t_list **a, t_list **b)
{
    t_list  *temp;

    temp = *a;
    while (temp->next != *a)
    {
        perform_movement(a, b);
        temp = temp->next;
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
        char *debug_argv[] = {"push_swap", "4 3 2 6", "5"};
        argc = 2;
        argv = debug_argv;
    }
    if (check_valid(argv, argc) == TRUE)
    {
        load_list(&list, argv, argc);
    }
    if ((disorder = check_duplicates(list)) == TRUE)
    {
        printf("Error");
        /*return (1);*/
        /* free list */
    }
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

    order_list(&list, &list3);
    printf("New list:\n%d\n", list->number);
    printf("%d\n", list->next->number);
    printf("%d\n", list->next->next->number);
    printf("%d\n", list->next->next->next->number);
    printf("%d\n", list->next->next->next->next->number);

    return (0);
}
