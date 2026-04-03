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
    int lis;
    int in_lis;
    int cost_a;
    int cost_b;
    struct s_list   *lis_start;
    struct s_list   *next;
    struct s_list   *prev;
}   t_list;

int    valid_atoi(const char *nptr, int *nbr)
{
	long    result;
	int index;
	int sign;

	result = 0;
	index = 0;
	sign = 1;
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
			sign = -1 * sign;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result = result * 10 + (nptr[index] - '0');
        if (sign == 1 && result > 2147483647)
            return 0; 
        if (sign == -1 && -result < -2147483648)
            return 0;
		index++;
	}
    *nbr = sign * result;
	return (1);
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
    node->lis = 1;
    node->in_lis = 0;
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
    write(1, "pa\n", 3);
}

void    pb(t_list **a, t_list **b)
{
    push(b, a);
    write(1, "pb\n", 3);
}

void    ra(t_list **a, t_list **b)
{
    t_list *temp;

    temp = *a;
    *a = (*a)->next;   
    ft_lstadd_back(a, temp); 
    write(1, "ra\n", 3);
}

void    rb(t_list **a, t_list **b)
{
    t_list *temp;

    temp = *b;
    *b = (*b)->next;   
    ft_lstadd_back(b, temp);  
    write(1, "rb\n", 3);
}

void    rr(t_list **a, t_list **b)
{
    t_list *temp_a;
    t_list *temp_b;

    temp_a = *a;
    temp_b = *b;
    *a = (*a)->next; 
    *b = (*b)->next;   
    ft_lstadd_back(a, temp_a);       
    ft_lstadd_back(b, temp_b); 
    write(1, "rr\n", 3);
}

void    rra(t_list **a, t_list **b)
{
    t_list *tail;

    if (!a || !(*a) || !(*a)->next) // lista vacía o un solo nodo
        return;
    tail = *a;
    while (tail->next)          // buscar el último nodo
        tail = tail->next;
    // desconectar el tail
    if (tail->prev)
        tail->prev->next = NULL;
    tail->prev = NULL;
    tail->next = *a;
    (*a)->prev = tail;
    *a = tail;                  // actualizar head
    write(1, "rra\n", 4);
}

void rrb(t_list **a, t_list **b)
{
    t_list *tail;

    if (!b || !(*b) || !(*b)->next) // lista vacía o un solo nodo
        return;
    tail = *b;
    while (tail->next)          // buscar el último nodo
        tail = tail->next;
    // desconectar el tail
    if (tail->prev)
        tail->prev->next = NULL;
    tail->prev = NULL;
    tail->next = *b;
    (*b)->prev = tail;
    *b = tail;                  // actualizar head
    write(1, "rrb\n", 4);
}

void    rra_no_print(t_list **a, t_list **b)
{
    t_list *tail;

    if (!a || !(*a) || !(*a)->next) // lista vacía o un solo nodo
        return;
    tail = *a;
    while (tail->next)          // buscar el último nodo
        tail = tail->next;
    // desconectar el tail
    if (tail->prev)
        tail->prev->next = NULL;
    tail->prev = NULL;
    tail->next = *a;
    (*a)->prev = tail;
    *a = tail;                  // actualizar head
}

void rrb_no_print(t_list **a, t_list **b)
{
    t_list *tail;

    if (!b || !(*b) || !(*b)->next) // lista vacía o un solo nodo
        return;
    tail = *b;
    while (tail->next)          // buscar el último nodo
        tail = tail->next;
    // desconectar el tail
    if (tail->prev)
        tail->prev->next = NULL;
    tail->prev = NULL;
    tail->next = *b;
    (*b)->prev = tail;
    *b = tail;                  // actualizar head
}

void    rrr(t_list **a, t_list **b)
{
    rra_no_print(a, b);
    rrb_no_print(a, b);
    write(1, "rrr\n", 4);
}

void free_list(t_list *list)
{
    t_list *temp;
    t_list *next;

    while (list)
    {
        next = list->next;
        free(list);
        list = next;
    }
}

// PARSING
/* Checks if characters are valid, if '-' is the initial one or it's preceeded by ' ' */
int check_valid(char **argv, int argc)
{
    int i;
    int j;
    char *str;

    i = 1;
    while (i < argc)
    {
        str = argv[i];
        j = 0;
        while (str[j] != '\0')
        {
            if (str[j] == '-')
            {
                if (str[j + 1] == '\0' || !(str[j + 1] >= '0' && str[j + 1] <= '9'))
                    return (FALSE);
                else if (!(j == 0 || str[j - 1] == ' '))
                    return (FALSE);
            }
            if (!(str[j] >= '0' && str[j] <= '9') && str[j] != ' ')
                return (FALSE);
            j++;
        }
        i++;
    }
    return (TRUE); 
}

//Calculates duplicates and inversions at the same time 
int check_duplicates(t_list *list)
{
    t_list  *current;
    t_list  *temp;

    current = list;
    while (current)
    {
        temp = current->next;
        while (temp)
        {
            if (current->number == temp->number) 
            {
                return (TRUE);
            }
            temp = temp->next;
        }
        current = current->next;
    }
    return (FALSE);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	if (!dest && !src)
	{
		return (NULL);
	}
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	index = 0;
	while (index < n)
	{
		ptr_dest[index] = ptr_src[index];
		index++;
	}
	return (dest);
}

char	*ft_realloc(char *ptr, size_t size, int n_char)
{
	char	*line;

	line = malloc(sizeof(char) * size);
	if (!line)
		return (NULL);
	if (ptr)
	{
		ft_memcpy(line, ptr, n_char);
		free (ptr);
		ptr = NULL;
	}
	return (line);
}

int ft_strlen(char *str)
{
    int index;

    index = 0;
    while (str[index] != '\0')
    {
        index++;
    }
    return (index);
}

char *join_arguments(char **argv, int argc)
{
    int index = 1;
    int size;
    int len = 0;
    char *str = NULL;

    while (index < argc)
    {
        size = ft_strlen(argv[index]);
        str = ft_realloc(str, len + size + 2, len);
        if (!str)
            return (NULL);
        ft_memcpy(str + len, argv[index], size);
        len += size;

        if (index < argc - 1)
            str[len++] = ' ';

        str[len] = '\0';
        index++;
    }
    return (str);
}

// LOADING
int    load_list(t_list **list, char *new_argv)
{
    int flag;
    int nbr;
    t_list  *node;

    flag = 0;
    while (*new_argv != '\0')
    {
        if (((*new_argv >= '0' && *new_argv <= '9') || *new_argv == '-') && flag == 0)
        {
            if (!valid_atoi(new_argv, &nbr))
                return (FALSE);
            node = ft_create_node(nbr);
            ft_lstadd_back(list, node);
            flag = 1;
            if (*new_argv == '-')
                new_argv++;
            while (*new_argv >= '0' && *new_argv <= '9')
                new_argv++;
            continue;
        }
        else if (*new_argv == ' ')
            flag = 0; 
        new_argv++;
    }
    return (TRUE);
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

int    list_size(t_list *list)
{
    t_list  *temp;
    int size;

    temp = list;
    size = 0;
    while (temp)
    {
        size++;
        temp = temp->next;
    }
    return (size);
}

// CALCULATE LIS
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

// CALCULATE COSTS
int    cost_b(t_list *b, t_list *node)
{
    t_list *temp;
    int size = list_size(b);
    int cost_rb = 0;
    int cost_rrb = 0;

    temp = b;
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

int    cost_a(t_list *a, t_list *node)
{
    t_list *temp;
    int size = list_size(a);
    int cost_ra = 0;
    int cost_rra = 0;

    temp = a;
    while (temp && temp->index < node->index)
    {
        cost_ra++;
        temp = temp->next;
    }
    if (!temp)
        return (0);
    cost_rra = size - cost_ra;
    if (cost_ra > cost_rra)
        return (-cost_rra);
    else
        return (cost_ra);
}

void    apply_costs(t_list *a, t_list *b)
{
    t_list *temp = b;
    while (temp)
    {
        temp->cost_a = cost_a(a, temp);
        temp->cost_b = cost_b(b, temp);
        temp = temp->next;
    }
}

int abs(int n)
{
    return (n < 0) ? -n : n;
}

int max(int a, int b) {
    return (a > b) ? a : b;
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
    int total_cost = 0;
    int cheapest_cost = 0;

    temp = b;
    cheapest = b;
    while (temp)
    {
        if (cost_a )
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

/*void rotate_both(t_list **a, t_list **b, t_list *node, int *n_mov)
{
    while (node->cost_a > 0 && node->cost_b > 0)
    {
        rr(a, b);
        node->cost_a--;
        node->cost_b--;
        (*n_mov)++;
    }
    while (node->cost_a < 0 && node->cost_b < 0)
    {
        rrr(a, b);
        node->cost_a++;
        node->cost_b++;
        (*n_mov)++;
    }
}

void rotate_single(t_list **a, t_list **b, t_list *node, int *n_mov)
{
    while (node->cost_a > 0)
    {
        ra(a, b);
        node->cost_a--;
        (*n_mov)++;
    }
    while (node->cost_a < 0)
    {
        rra(a, b);
        node->cost_a++;
        (*n_mov)++;
    }
    while (node->cost_b > 0)
    {
        rb(a, b);
        node->cost_b--;
        (*n_mov)++;
    }
    while (node->cost_b < 0)
    {
        rrb(a, b);
        node->cost_b++;
        (*n_mov)++;
    }
}

void apply_rotations(t_list **a, t_list **b, t_list *node, int *n_mov)
{
    rotate_both(a, b, node, n_mov);
    rotate_single(a, b, node, n_mov);
    pa(a, b);
    (*n_mov)++;
}*/

void apply_rotations(t_list **a, t_list **b, t_list *node, int *n_mov)
{
    while (node->cost_a > 0 && node->cost_b > 0) 
    { 
        rr(a, b); 
        node->cost_a--; 
        node->cost_b--; 
        n_mov++; 
    } 
    while (node->cost_a < 0 && node->cost_b < 0) 
    { 
        rrr(a, b); 
        node->cost_a++; 
        node->cost_b++; 
        n_mov++; 
    } 
    while (node->cost_a > 0) 
    { 
        ra(a, b); 
        node->cost_a--; 
        n_mov++; 
    } 
    while (node->cost_a < 0) 
    { 
        rra(a, b); 
        node->cost_a++; 
        n_mov++; 
    } 
    while (node->cost_b > 0) 
    { 
        rb(a, b); 
        node->cost_b--; 
        n_mov++; 
    } 
    while (node->cost_b < 0) 
    { 
        rrb(a, b); 
        node->cost_b++; 
        n_mov++; 
    } 
    pa(a, b); 
    n_mov++;
}
void    reinsertion(t_list **a, t_list **b, int *n_mov)
{
    while (*b)
    {
        apply_costs(*a, *b);                  // actualizar costes
        t_list *node = find_cheapest_node(*b);   // nodo más barato
        apply_rotations(a, b, node, n_mov);        // mover nodo y push a A
    }
}

void    return_a_to_origin(t_list **a, int *n_mov)
{
    t_list *temp;
    int cost_ra;
    int cost_rra;

    temp = *a;
    cost_ra = 0;
    cost_rra = 0;
    while (temp && temp->index != 0)
    {
        cost_ra++;
        temp = temp->next;
    }
    cost_rra = list_size(*a) - cost_ra;
    if (cost_ra <= cost_rra)
    {
        while(cost_ra-- > 0)
        {
            ra(a, NULL);
            (*n_mov)++;
        }    
    }
    else
    {
        while(cost_rra-- > 0)
        {
            rra(a, NULL);
            (*n_mov)++;
        }      
    }
}

int main(int argc, char **argv)
{
    int index;
    t_list  *list = NULL;
    t_list  *aux = NULL;
    t_list  *list3 = NULL;
    t_list  *node;
    char *new_argv;

    index = 0;
    if (argc < 2)
    {
        char *debug_argv[] = {"push_swap", "42 7 89 13 56 21 78 3 91 34 65 12 88 27 54 6 73 19 84 2 97 45 68 23 51 9 76 30 82 14 60 1 95 38 71 25 53 11 86 4 79 33 66 18 90 47 70 28 55 8 99 36 62 16 83 5 77 41 64 20 92 31 58 10 87 44 69 22 50 15 93 39 72 26 57 17 80 35 61 24 94 40 67 29 52 43 74 32 63 46 81 37 59 48 75 49 85 96 98 100"};
        argc = 2;
        argv = debug_argv;
    }
    if (check_valid(argv, argc) == FALSE)
        return (1);

    new_argv = join_arguments(argv, argc);
    if (load_list(&list, new_argv) == FALSE)
    {
        free_list(list);
        return (1);
    }
    if (check_duplicates(list) == TRUE)
    {
        write(1, "Error\n", 6);
        free_list(list);
        return (1);
    }

    aux = list;
    printf("Initial list:\n");
    while (aux != NULL)
    {
        printf("%d\n", aux->number);
        aux = aux->next;
    }

    apply_index(&list);

    aux = list;
    printf("Indexes:\n");
    while (aux != NULL)
    {
        printf("%d\n", aux->index);
        aux = aux->next;
    }

    t_list *lis_end = calculate_lis_end(list);
    printf("End node: %d\n", lis_end->number);

    t_list *lis_start = calculate_lis_start(list, lis_end);
    printf("Start node: %d\n", lis_start->number);

    int size = list_size(list);
    
    int n_mov = keep_lis_in_a(&list, &list3);

    printf("Movimientos:%d\n", n_mov);

    printf("List A after pushing numbers to B:\n");
    aux = list;
    while (aux != NULL)
    {
        printf("%d\n", aux->number);
        aux = aux->next;
    }

    printf("List B after pushing numbers to B:\n");
    aux = list3;
    while (aux != NULL)
    {
        printf("Holas%d\n", aux->number);
        aux = aux->next;
    }

    //n_mov += re_order_list(&list, &list3, size);

    reinsertion(&list, &list3, &n_mov);

    return_a_to_origin(&list, &n_mov);

    printf("List A after returning numbers from B:\n");
    aux = list;
    while (aux != NULL)
    {
        printf("%d\n", aux->number);
        aux = aux->next;
    }

    printf("List B after returning numbers from B:\n");
    aux = list3;
    while (aux != NULL)
    {
        printf("%d\n", aux->number);
        aux = aux->next;
    }

    printf("Movimientos:%d\n", n_mov);

    return (0);
}
