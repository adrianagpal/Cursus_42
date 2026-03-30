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
    int index;
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

void    sa(t_list **a, t_list **b)
{
    swap(a);
    /*write(1, "sa\n", 3);*/
}

void    sb(t_list **a, t_list **b)
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

void    ra(t_list **a, t_list **b)
{
    *a = (*a)->next;    
    /*write(1, "ra\n", 3);*/
}

void    rb(t_list **a, t_list **b)
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

void    rra(t_list **a, t_list **b)
{
    *a = (*a)->prev;    
    /*write(1, "rra\n", 4);*/
}

void    rrb(t_list **a, t_list **b)
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

    index = 1;
    while (index < argc)
    {
        j = 0;
        while ((ch = argv[index][j]) != '\0')
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

    index = 1;
    while (index < argc)
    {
        j = 0;
        flag = 0;
        while (argv[index][j] != '\0')
        {
            /* Falta comprobar si hay signos - seguidos */
            if (((argv[index][j] >= '0' && argv[index][j] <= '9') || argv[index][j] == '-') && flag == 0)
            {
                node = ft_create_node(ft_atoi(&argv[index][j]));
                ft_lstadd_back(list, node);
                flag = 1;
            }
            else if (argv[index][j] == ' ')
            {
               flag = 0; 
            } 
            j++;
        }
        index++;
    }
}

void free_list(t_list *list)
{
    if (!list)
        return;

    t_list *start = list;
    t_list *tmp;

    do {
        tmp = list;
        list = list->next;
        free(tmp);
    } while (list != start);
}

void    copy_list(t_list **list, t_list **new_list)
{
    t_list  *temp;
    t_list  *node;

    *new_list = NULL;

    if (!list || !*list)
        return;

    temp = *list;

    node = ft_create_node(temp->number);
    if (!node)
        return;
    ft_lstadd_back(new_list, node);
    temp = temp->next;
    while (temp != *list)
    {
        node = ft_create_node(temp->number);
        if (!node)
            return;
        ft_lstadd_back(new_list, node);
        temp = temp->next;
    }
}

/* Calculates duplicates and inversions at the same time */
int check_duplicates(t_list *list)
{
    t_list  *current;
    t_list  *temp;
    int inv;

    if (!list)
        return (-1);

    if (list->next == list)
        return 0;

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

void check_best_movement(t_list *a, t_list *b, t_list **new_a, t_list **new_b)
{
    printf("copiando listas...\n");
    copy_list(&a, new_a);
    //copy_list(b, new_b);
    printf("copias hechas\n");
}

 
/*int order_list(t_list **a, t_list **b)
{
    t_list *new_a = NULL;
    t_list *new_b = NULL;
    int n_mov = 0;
    void (*movs[11])(t_list **, t_list **) = {
        sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr
    };

    char *mov_names[11] = {
        "sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"
    };

    while (check_duplicates(*a) > 0)
    {
        int *best = check_best_movement(a, b); // índices de los 3 mejores movimientos

        for (int i = 0; i < 3; i++)
        {
            movs[best[i]](a, b);  
            n_mov++;          // aplicar movimiento
            printf("%s\n", mov_names[best[i]]); // imprimir el movimiento
        }
    }
    return (n_mov);
}*/

int main(int argc, char **argv)
{
    int index;
    t_list  *list = NULL;
    t_list  *list2 = NULL;
    t_list  *list3 = NULL;
    t_list  *list4 = NULL;
    t_list  *node;
    int disorder = 0;

    index = 0;
    if (argc < 2)
    {
        char *debug_argv[] = {"push_swap", "2 3 5 7 8 4 643 2543 21", "5"};
        argc = 2;
        argv = debug_argv;
    }
    if (check_valid(argv, argc) == TRUE)
    {
        load_list(&list, argv, argc);
    }
    if ((disorder = check_duplicates(list)) == -1)
    {
        printf("Error");
        return (1);
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
    printf("%d\n", list->next->next->next->next->next->number);
    printf("%d\n", list->next->next->next->next->next->next->number);
    printf("%d\n", list->next->next->next->next->next->next->next->number);
    printf("%d\n", list->next->next->next->next->next->next->next->next->number);

    printf("list = %p\n", (void*)list);
    check_best_movement(list, list3, &list2, &list4);

    printf("hola");

    /*int check = check_duplicates(list);
    printf("Duplicates:%d\n", check);
    printf("Inversions:%d\n", inv);*/

    //int n_mov = order_list(&list, &list3);

    //printf("Number of movements: %d\n", n_mov);

    printf("New list:\n%d\n", list3->number);
    printf("%d\n", list3->next->number);
    printf("%d\n", list3->next->next->number);
    printf("%d\n", list3->next->next->next->number);
    printf("%d\n", list3->next->next->next->next->number);
    printf("%d\n", list3->next->next->next->next->next->number);
    printf("%d\n", list3->next->next->next->next->next->next->number);
    printf("%d\n", list3->next->next->next->next->next->next->next->number);
    printf("%d\n", list3->next->next->next->next->next->next->next->next->number);

    return (0);
}
