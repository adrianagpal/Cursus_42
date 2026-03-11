#include <stdio.h>
#include <stdlib.h>
#include "push_swap_library.h"

typedef struct t_list
{
    void    *content;
    struct t_list    *next;
}   s_list;

s_list  *create_node(int *content)
{
    s_list  *node;

    node = malloc(sizeof(s_list));
    if (!node)
    {
        return (NULL);
    }
    node->content = content;
    node->next = NULL;
    return (node);
}

s_list  *ft_lstlast(s_list *list)
{
    s_list  *temp;

    if (!list)
    {
        return (NULL);
    }
    temp = list;
    while (temp != NULL)
    {
        if (temp->next == NULL || temp->next == list)
        {
            return (temp);
        }
        temp = temp->next;
    }
    return (NULL);
}

void    ft_lstadd_back(s_list **list, s_list *node)
{
    s_list  *last;

    if (!list || !node)
    {
        return ;
    }
    if (*list == NULL)
    {
        *list = node;
        return ;
    }
    last = ft_lstlast(*list);
    last->next = node;
}

s_list  *array_to_list(int *stack, size_t size)
{
    s_list  *list;
    s_list  *node;
    size_t index;

    if (!stack || size == 0)
        return (NULL);
    index = 0;
    list = NULL;
    while (index < size)
    {
        node = create_node(&stack[index]);
        ft_lstadd_back(&list, node);
        index++;
    }
    return (list);
}

int main(void)
{
    s_list  *list;
    s_list  *list2;
    s_list  *node1;
    s_list  *node2;
    s_list  *node3;
    s_list  *node4;
    s_list  *last;

    /*node1 = create_node("hola");
    node2 = create_node("que");
    node3 = create_node("tal");
    node4 = create_node("adios");

    list = node1;
    ft_lstadd_back(&list, node2);
    ft_lstadd_back(&list, node3);

    printf("%s", (char *)list->content);*/

    int    arr[5];
    int index = 0;

    arr[0] = 4;
    arr[1] = 2;
    arr[2] = 1;
    arr[3] = 6;
    arr[4] = 8;

    list2 = array_to_list(arr, 5);

    /* Hay que hacerlo así porque printf recorre la lista hasta que encuentra un |0 e imprime toda la lista*/
    printf("%d", *(int *)((list2->next)->content));
}

