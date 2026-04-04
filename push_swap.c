#include "push_swap.h"

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
    t_list  *list = NULL;
    t_list  *aux = NULL;
    t_list  *list3 = NULL;
    int n_mov;
    char *new_argv;

    if (argc == 1)
        return (0);
    /*if (argc < 2)
    {
        char *debug_argv[] = {"push_swap", "89 45 1 2"};
        argc = 2;
        argv = debug_argv;
    }*/
    if (check_valid(argv, argc) == FALSE)
    {
        write(2, "Error\n", 6);
        exit(EXIT_FAILURE);
    }
    new_argv = join_arguments(argv, argc);
    if (load_list(&list, new_argv) == FALSE)
    {
        write(2, "Error\n", 6);
        free_list(list);
        exit(EXIT_FAILURE);
    }
    if (check_duplicates(list) == TRUE)
    {
        write(2, "Error\n", 6);
        free_list(list);
        exit(EXIT_FAILURE);
    }
    apply_index(&list);    
    keep_lis_in_a(&list, &list3, &n_mov);
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
        printf("%d\n", aux->number);
        aux = aux->next;
    }
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
