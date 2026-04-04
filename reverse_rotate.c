#include "push_swap.h"

void    rra(t_list **a, t_list **b)
{
    t_list *tail;

    if (!a || !(*a) || !(*a)->next) // lista vacía o un solo nodo
        return;
    tail = *a;
    while (tail->next)          // buscar el último nodo
        tail = tail->next;
    // desconectar el tail
    if (tail->prev)
        tail->prev->next = NULL;
    tail->prev = NULL;
    tail->next = *a;
    (*a)->prev = tail;
    *a = tail;                  // actualizar head
    write(1, "rra\n", 4);
}

void rrb(t_list **a, t_list **b)
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
    write(1, "rrb\n", 4);
}

void    rra_no_print(t_list **a, t_list **b)
{
    t_list *tail;

    if (!a || !(*a) || !(*a)->next) // lista vacía o un solo nodo
        return;
    tail = *a;
    while (tail->next)          // buscar el último nodo
        tail = tail->next;
    // desconectar el tail
    if (tail->prev)
        tail->prev->next = NULL;
    tail->prev = NULL;
    tail->next = *a;
    (*a)->prev = tail;
    *a = tail;                  // actualizar head
}

void rrb_no_print(t_list **a, t_list **b)
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
    rra_no_print(a, b);
    rrb_no_print(a, b);
    write(1, "rrr\n", 4);
}