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

/*void    copy_list(t_list **list, t_list **new_list)
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
    while (temp != NULL)
    {
        node = ft_create_node(temp->number);
        if (!node)
            return;
        ft_lstadd_back(new_list, node);
        temp = temp->next;
    }
}

 Calculates duplicates and inversions at the same time 
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
            printf("%dy%d:", current->number, temp->number);
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

void apply_index(t_list **aux)
{
    t_list  *temp;
    int index_aux;

    index_aux = 0;
    temp = *aux;
    (*aux)->index = index_aux;
    index_aux++;
    temp = temp->next;    
    while (temp != *aux)
    {
        temp->index = index_aux;
        index_aux++;
        temp = temp->next;
    }    
}*/

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
            

/*int    calculate_lis(t_list *a)
{
    t_list *prev;
    int mx;
    int val;

    prev = (a)->prev;
    mx = 0;
    while (prev)
    {
        if (prev->index < a->index)
        {
            val = calculate_lis(prev) + 1;
            if (val > mx)
                mx = val;
        }
        prev = prev->prev;
    }
    return (mx);
}

int find_lis(t_list *a)
{
    t_list *current;
    int res;
    int val;

    res = 0;
    current = a;
    while (current)
    {
        val = calculate_lis(current);
        if (val > res)
            res = val;
        current = current->next;
    }
    return (res);
}

void order_list(t_list **a, t_list **b)
{
    t_list *temp;
    t_list *min;
    int size = 0;
    
    int index = 0;
    temp = *a;  
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }  
    while (size/2 > 0)
    {
        temp = *a;
        if (temp->index > temp->next->index)
        {
            pb(a,b);
            write(1, "pb\n", 3);
        }
        else
        {
            ra(a);
            write(1, "ra\n", 3);
        }
        size--;        
    }
}


    *a;
    size = 1;
    temp = temp->next;
    while (temp != *a)
    {
        size++;
        temp = temp->next;
    }
    min = (*a)->index;
    while (index < size)
    {
        if ((*a)->index > min)
        {
            pb(a, b);
            min = (*a)->next->index;
            write(1, "pb\n", 3);
        }
        else
        {

        }

            ra(a);
            write(1, "ra\n", 3);
            index++;
        }
        else if ((*a)->index == index + 1 && (*a)->next->index == index)
        {
            sa(a);
            ra(a);
            write(1, "sa\nra\n", 6);
            index++;
        }
        else
        {
            pb(a, b);
            write(1, "pb\n", 3);
        }
    }        
}*/



int main(int argc, char **argv)
{
    int index;
    t_list  *list = NULL;
    t_list  *aux = NULL;
    t_list  *list3 = NULL;
    t_list  *node;
    int disorder = 0;

    index = 0;
    if (argc < 2)
    {
        char *debug_argv[] = {"push_swap", "342 581 109 204 603 475 888 1001 250 732 319 407 820 119 902 640 215 367 591 804 134 711 28 655 920 301 473 811 536 122 673 777 253 698 834 299 412 583 999 623 140 375 870 228 192 405 760 138 514 223 451 892 314 187 660 431 772 219 274 907 311 684 529 61 744 206 816 221 593 487 739 205 665 831 478 906 302 154 839 317 997 630 284 775 418 543 699 810 261 383 922 156 471 318 802 267 901 432 589 773 150 621 886 444"};
        argc = 2;
        argv = debug_argv;
    }
    if (check_valid(argv, argc) == TRUE)
    {
        load_list(&list, argv, argc);
    }
    /*if ((disorder = check_duplicates(list)) == -1)
    {
        printf("Error");
        return (1);
        free list 
    }*/
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

    printf("New list:\n%d\n", list->number);
    printf("%d\n", list->next->number);
    printf("%d\n", list->next->next->number);
    printf("%d\n", list->next->next->next->number);
    printf("%d\n", list->next->next->next->next->number);
    printf("%d\n", list->next->next->next->next->next->number);
    printf("%d\n", list->next->next->next->next->next->next->number);
    printf("%d\n", list->next->next->next->next->next->next->next->number);

    apply_index(&list);
    //order_list(&list, &list3);

    printf("List with indexes:\n%d\n", list->index);
    printf("%d\n", list->next->index);
    printf("%d\n", list->next->next->index);
    printf("%d\n", list->next->next->next->index);
    printf("%d\n", list->next->next->next->next->index);
    printf("%d\n", list->next->next->next->next->next->index);
    printf("%d\n", list->next->next->next->next->next->next->index);
    printf("%d\n", list->next->next->next->next->next->next->next->index);

    aux = list;
    printf("Numbers of list\n");
    while (aux != NULL)
    {
        printf("%d\n", aux->number);
        aux = aux->next;
    }

    t_list *lis_end = calculate_lis_end(list);
    printf("End node: %d\n", lis_end->number);

    t_list *lis_start = calculate_lis_start(list, lis_end);
    printf("Start node: %d\n", lis_start->number);

    int size = list_size(list);
    
    int n_mov = order_list(&list, &list3);

    printf("Nueva lista A:\n");
    aux = list;
    while (aux != NULL)
    {
        printf("%d\n", aux->number);
        aux = aux->next;
    }

    printf("Nueva lista B:\n");
    aux = list3;
    while (aux != NULL)
    {
        printf("%d\n", aux->number);
        aux = aux->next;
    }

    n_mov += re_order_list(&list, &list3, size);

    printf("Segunda Nueva lista A:\n");
    aux = list;
    while (aux != NULL)
    {
        printf("%d\n", aux->number);
        aux = aux->next;
    }

    printf("Segunda Nueva lista B:\n");
    aux = list3;
    while (aux != NULL)
    {
        printf("%d\n", aux->number);
        aux = aux->next;
    }

    printf("Movimientos:%d\n", n_mov);

    return (0);
}
