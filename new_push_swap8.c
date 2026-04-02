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
    t_list *temp;

    temp = *a;
    *a = (*a)->next;   
    ft_lstadd_back(a, temp); 
    /*write(1, "ra\n", 3);*/
}

void    rb(t_list **b)
{
    t_list *temp;

    temp = *b;
    *b = (*b)->next;   
    ft_lstadd_back(b, temp);  
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

void rrb(t_list **b)
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
    *a = (*a)->prev; 
    *b = (*b)->prev;    
    /*write(1, "rrr\n", 4);*/
}

/* CHECK ERRORS */
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

int max(int a, int b) {
    return (a > b) ? a : b;
}

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

int    order_list(t_list **a, t_list **b)
{
    int size = list_size(*a);
    int index = 0;
    int n_mov = 0;

    while (index < size)
    {
        if ((*a)->in_lis == 0)
        {
            pb(a, b);
            write(1, "pb\n", 3);
            n_mov++;
        }
        else
        {
            ra(a);
            write(1, "ra\n", 3);
            n_mov++;
        } 
        index++;
    }
    return (n_mov);
}

int rb_vs_rrb(t_list *b, int index)
{
    t_list *temp = b;
    int n_rb = 0;
    int size = 0;

    // Contar tamaño de la lista
    while (temp)
    {
        size++;
        temp = temp->next;
    }

    // Contar cuántos pasos hacia arriba (rb) para llegar al index
    temp = b;
    n_rb = 0;
    while (temp && temp->index != index)
    {
        n_rb++;
        temp = temp->next;
    }

    int n_rrb = size - n_rb;

    // Si hacer rb es más caro o igual, conviene rrb
    return (n_rb >= n_rrb);
}

int    re_order_list(t_list **a, t_list **b, int size)
{
    int index = 0;
    int n_mov = 0;
    int n_rb = 0;

    while (index < size)
    {
        if ((*a)->index == index)
        {
            ra(a);
            write(1, "ra\n", 3);
            index++;
            n_mov++;
            n_rb = rb_vs_rrb(*b, index);
        }
        else if (*b && (*b)->index == index)
        {
            pa(a, b);
            write(1, "pa\n", 3);
            ra(a);
            write(1, "ra\n", 3);
            index++;
            n_mov++;
            n_mov++;
        }
        else
        {
            if (n_rb == 0)
            {
                rb(b);
                write(1, "rb\n", 3);
            }
            if (n_rb == 1)
            {
                rrb(b);
                write(1, "rrb\n", 4);
            }
            n_mov++;
        } 
    }
    return (n_mov);
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
        char *debug_argv[] = {"push_swap", "7 5 2 1 3 6 4 8 7", "9"};
        argc = 2;
        argv = debug_argv;
    }
    if (check_valid(argv, argc) == FALSE)
        return (1);

    new_argv = join_arguments(argv, argc);
    if (load_list(&list, new_argv) == FALSE)
    {
        //free
        return (1);
    }
    if (check_duplicates(list) == TRUE)
    {
        write(1, "Error\n", 6);
        //free
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
    
    int n_mov = order_list(&list, &list3);

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
        printf("%d\n", aux->number);
        aux = aux->next;
    }

    n_mov += re_order_list(&list, &list3, size);

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
