#include <stdio.h>

void    swap(int *array, size_t size)
{
    int temp;

    if (size < 2)
    {
        return ;
    }
    temp = array[0];
    array[0] = array[1];
    array[1] = temp;
}

void    push(int *a, int *b, size_t size)
{
    int index;

    index = 0;
    while (size > 0)
    {
        a[size] = a[size - 1];
        size--;
    }
    a[0] = b[0];
    while (index < size)
    {
        b[index] = b[index + 1];
        index ++;
    }
}

void    sa(int *a)
{
    swap(a);
}

void    sb(int *b)
{
    swap(b);
}



int main(void)
{
    int    a[5];
    int    b[5];
    int index;

    index = 0;
    b[0] = 3;
    b[1] = 2;
    b[2] = 6;
    b[3] = 9;
    b[4] = 0;

    while (index < 5)
    {
        printf("%d", b[index]);
        index++;
    }

    push(b, a, 5);

    index = 0;
    while (index < 5)
    {
        printf("%d", a[index]);
        index++;
    }
    index = 0;
    while (index < 5)
    {
        printf("%d", b[index]);
        index++;
    }

    return (0);
}