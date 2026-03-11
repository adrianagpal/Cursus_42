#include <stdlib.h>
#include "push_swap_library.h"

void    swap(s_list **list, size_t size)
{
    s_list  *temp;

    if (size < 2)
        return ;
    temp = *list;

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