
# ifndef PUSH_SWAP_LIBRARY
#define PUSH_SWAP_LIBRARY 

typedef struct t_list
{
    int content;
    struct t_list    *next;
}   s_list;

s_list  *create_node(int *content);
s_list  *ft_lstlast(s_list *list);
void    ft_lstadd_back(s_list **list, s_list *node);
s_list  *array_to_list(int *stack, size_t size);


#endif
