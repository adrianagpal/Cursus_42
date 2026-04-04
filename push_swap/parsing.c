#include "push_swap.h"

// PARSING
/* Checks if characters are valid, if '-' is the initial one or it's preceeded by ' ' */
int check_valid(char **argv, int argc)
{
    int i;
    int j;
    char *str;

    i = 1;
    while (i < argc)
    {
        str = argv[i];
        j = 0;
        while (str[j] != '\0')
        {
            if (str[j] == '-')
            {
                if (str[j + 1] == '\0' || !(str[j + 1] >= '0' && str[j + 1] <= '9'))
                    return (FALSE);
                else if (!(j == 0 || str[j - 1] == ' '))
                    return (FALSE);
            }
            else if (!(str[j] >= '0' && str[j] <= '9') && str[j] != ' ')
                return (FALSE);
            j++;
        }
        i++;
    }
    return (TRUE); 
}

//Calculates duplicates and inversions at the same time 
int check_duplicates(t_list *list)
{
    t_list  *current;
    t_list  *temp;

    current = list;
    while (current)
    {
        temp = current->next;
        while (temp)
        {
            if (current->number == temp->number) 
            {
                return (TRUE);
            }
            temp = temp->next;
        }
        current = current->next;
    }
    return (FALSE);
}

char *join_arguments(char **argv, int argc)
{
    int index;
    int size;
    int len;
    char *str;

    index = 1;
    len = 0;
    str = NULL;
    while (index < argc)
    {
        size = ft_strlen(argv[index]);
        str = ft_realloc(str, len + size + 2, len);
        if (!str)
            return (NULL);
        ft_memcpy(str + len, argv[index], size);
        len += size;

        if (index < argc - 1)
            str[len++] = ' ';

        str[len] = '\0';
        index++;
    }
    return (str);
}

int    valid_atoi(const char *nptr, int *nbr)
{
	long    result;
	int index;
	int sign;

	result = 0;
	index = 0;
	sign = 1;
	if (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index] == '-')
			sign = -1 * sign;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result = result * 10 + (nptr[index] - '0');
        if (sign == 1 && result > 2147483647)
            return 0; 
        if (sign == -1 && -result < -2147483648)
            return 0;
		index++;
	}
    *nbr = sign * result;
	return (1);
}

// LOADING
int    load_list(t_list **list, char *new_argv)
{
    int flag;
    int nbr;
    t_list  *node;

    flag = 0;
    while (*new_argv != '\0')
    {
        if (((*new_argv >= '0' && *new_argv <= '9') || *new_argv == '-') && flag == 0)
        {
            if (!valid_atoi(new_argv, &nbr))
                return (FALSE);
            node = ft_create_node(nbr);
            ft_lstadd_back(list, node);
            flag = 1;
            if (*new_argv == '-')
                new_argv++;
            while (*new_argv >= '0' && *new_argv <= '9')
                new_argv++;
            continue;
        }
        else if (*new_argv == ' ')
            flag = 0; 
        new_argv++;
    }
    return (TRUE);
}