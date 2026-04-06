#include "push_swap.h"

void    push_swap(t_list *a)
{
    int n_mov;
    t_list *b;

    b = NULL;
    apply_index(&a);    
    calculate_lis_end(a);
    keep_lis_in_a(&a, &b, &n_mov);    
    reinsertion(&a, &b, &n_mov);
    return_a_to_origin(&a, &b, &n_mov);

    printf("Movements:%d\n", n_mov);
}

/*void    push_swap_small(t_list *a, int *n_mov)
{
    t_list *temp;

    temp = a;
    while (temp)
    {
        if (temp->number > temp->next->number)
            sa(&a, &n_mov);
        ra(&a, &n_mov);
    }
}*/



int main(int argc, char **argv)
{
    t_list  *a;
    char *new_argv;

    if (argc == 1)
        return (0);
    if (check_valid(argv, argc) == FALSE)
    {
        write(2, "Error\n", 6);
        exit(EXIT_FAILURE);
    }
    new_argv = join_arguments(argv, argc);
    a = NULL;
    if (load_list(&a, new_argv) == FALSE || check_duplicates(a) == TRUE)
    {
        write(2, "Error\n", 6);
        free_list(a);
        exit(EXIT_FAILURE);
    }
    push_swap(a);
    return (0);
}
