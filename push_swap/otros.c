#include <stdlib.h>
#include <stdio.h>
/*#include "push_swap_library.h"*/

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

/* Finds last node of the list */
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

/* Adds node at the end of the list */
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
    node->next = *list;
}

void	ft_lstadd_front(s_list **list, s_list *new)
{
    s_list  *last;
	if (!list || !new)
	{
		return ;
	}
    if (*list == NULL)
    {
        *list = new;
        return ;
    }
	new->next = *list;
	*list = new;
    last = ft_lstlast(*list);
    last->next = *list;
}

s_list  *array_to_list(int *stack, size_t size)
{
    s_list  *list;
    s_list  *node;
    s_list  *last;
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
    last = list;
    while (last->next)
    {
        last = last->next;
    }
    last->next = list;
    return (list);
}

void    swap(s_list **list, size_t size)
{
    s_list  *temp;
    s_list  *next;
    s_list  *mem_next;

    if (size < 2)
        return ;
    temp = *list;
    mem_next = ((*list)->next)->next;

    *list = temp->next;
    (*list)->next = temp;    
    ((*list)->next)->next = mem_next;
}

void    push(s_list **a, s_list **b)
{
    s_list  *last;
    if (*b == NULL)
    {
        return ;
    }
    ft_lstadd_front(a, *b);
    last = ft_lstlast(*b);
    *b = (*b)->next;
    last->next = *b;
}







/*int main(void)
{
    char    arr[5];
    //char    b[5];
    int index = 0;

    arr[0] = 4;
    arr[1] = 2;
    arr[2] = 1;
    arr[3] = 6;
    arr[4] = 8;

    while (index < 5)
    {
        printf("%d", arr[index]);
        index++;
    }
    sa(arr);
    index = 0;
    while (index < 5)
    {
        printf("%d", arr[index]);
        index++;
    }


    return (0);
}*/

int main(void)
{
    s_list  *list;
    s_list  *list2;
    s_list  *node1;
    s_list  *node2;
    s_list  *node3;
    s_list  *node4;
    s_list  *last;

    int num1 = 32;
    int num2 = 5;
    int num3 = 68;
    int num4 = 122;

    node1 = create_node(&num1);
    node2 = create_node(&num2);
    node3 = create_node(&num3);
    node4 = create_node(&num4);

    list = node1;
    ft_lstadd_back(&list, node2);
    ft_lstadd_back(&list, node3);

    printf("%s", "hola");
    printf("%d", *(int*)list->content);

    push(list2, list);

    printf("%d", *(int*)list2->content);
}
