#include <stdio.h>

typedef struct t_list
{
    void    *content;
    struct t_list    *next;
}   t_list;

t_list  *create_node(char *content)
{
    t_list  *node;

    node = malloc(sizeof(t_list));
    if (!node)
    {
        return (NULL);
    }
    node->content = content;
    node->next = NULL;
    return (node);
}

t_list  add_node(t_list *list, char *content)
{
    t_list  *node;

    if (!list)
    {
        node = create_node(content);
    }
    list->next = &content;





}



void    array_to_list(char *stack, size_t size)
{
    int index;
    t_list  list;

    index = 0;
    while (index < size)
    {
        list.content = stack[index];

    }
}





void    swap(char *stack, size_t size)
{
    char    temp;

    if (size < 2)
        return ;
    temp = stack[0];
    stack[0] = stack[1];
    stack[1] = temp;
}

void    sa(char *a, size_t size)
{
    swap(a, size);
}

void    sb(char *b, size_t size)
{
    swap(b, size);
}

void    ss(char *a, char *b, size_t size)
{
    swap(a, size);
    swap(b, size);
}




int main(void)
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
}