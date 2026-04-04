#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_list
{
    int number;
    struct s_list   *next;
    struct s_list   *prev;
}   t_list;

int	ft_atoi(const char *nptr)
{
	int	result;
	int	index;
	int	sign;

	result = 0;
	index = 0;
	sign = 1;
	while (nptr[index] == ' ' || (nptr[index] >= 9 && nptr[index] <= 13))
	{
		index++;
	}
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
		{
			sign = -1 * sign;
		}
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result = result * 10 + (nptr[index] - '0');
		index++;
	}
	return (sign * result);
}

t_list  *ft_create_node(int number)
{
    t_list  *node;
    node = malloc(sizeof(t_list));
    if (!node)
    {
        return (NULL);
    }
    node->number = number;
    node->next = node;
    node->prev = node;
    return (node);
}

void    ft_lstadd_back(t_list **list, t_list *new)
{
    if (!list || !new)
    {
        return ;
    }
    if (!(*list))
    {
        *list = new;
        new->next = new;
        new->prev = new;
        return ;
    }
    new->prev = (*list)->prev;
    new->next = *list;
    (*list)->prev->next = new;
    (*list)->prev = new;
}

t_list  *load_list(char **argv, int n_arg)
{
    int index;
    t_list  *list;
    t_list  *node;

    index = 0;
    while (index < n_arg - 1)
    {
        node = ft_create_node(ft_atoi(argv[index + 1]));
        ft_lstadd_back(&list, node);
        index++;
    }
    return (list);
}

double compute_disorder(t_list **a)
{
    int mistakes;
    int total_pairs;
    t_list  *temp;

    if (!a || !(*a) || (*a)->next == *a)
        return (0);

    total_pairs = 0;
    mistakes = 0;
    temp = *a;
    while (temp->next != *a)
    {
        total_pairs += 1;
        if (temp->number > temp->next->number)
        {
            mistakes += 1;
        }
        temp = temp->next;
    }    
    printf("mistakes: %d\n", mistakes);
    printf("pairs: %d\n", total_pairs);
    return (1 - (double)mistakes / (double)total_pairs);
}

int main(int argc, char **argv)
{
    int index;
    t_list  *list = NULL;
    t_list  *list2 = NULL;
    t_list  *node;

    index = 0;
    if (argc < 2)
    {
        printf("Error");
        return (1);
    }
    list = load_list(argv, argc);
    
    printf("%d\n", list->number);
    printf("%d\n", list->next->number);
    printf("%d\n", list->next->next->number);
 
    double desorden = compute_disorder(&list);
    printf("%f\n", desorden);
    return (0);

}
