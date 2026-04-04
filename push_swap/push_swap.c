#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list  *list = NULL;
    t_list  *aux = NULL;
    t_list  *list3 = NULL;
    int n_mov;
    char *new_argv;

    if (argc == 1)
        return (0);
    if (argc < 2)
    {
        char *debug_argv[] = {"push_swap", "89 45 1 2"};
        argc = 2;
        argv = debug_argv;
    }
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
    
    reinsertion(&list, &list3, &n_mov);
    return_a_to_origin(&list, &list3, &n_mov);
    
    printf("List A after returning numbers from B:\n");
    aux = list;
    while (aux != NULL)
    {
        printf("%d\n", aux->number);
        aux = aux->next;
    }   
    printf("Movimientos:%d\n", n_mov);
    return (0);
}
