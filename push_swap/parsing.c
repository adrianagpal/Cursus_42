/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:52:14 by username          #+#    #+#             */
/*   Updated: 2026/04/09 16:03:43 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
check_valid checks wether the arguments contains only valid characters:
digits (0-9), spaces (' ') or a negative sign ('-'). For the negative
sign, it checks that:

- It appears either at the beginning of the string or immediately after a space.
- It is not placed at the end of the string.
- It is followed by a digit.

Return value:
- FALSE if any invalid character is found or any condition is not met.
- TRUE if the input is valid.
*/

t_bool	check_valid(char **argv, int argc)
{
	int		i;
	int		j;
	char	*s;

	i = 1;
	while (i < argc)
	{
		s = argv[i];
		j = 0;
		while (s[j] != '\0')
		{
			if (s[j] == '-')
			{
				if (s[j + 1] == '\0' || !(s[j + 1] >= '0' && s[j + 1] <= '9'))
					return (FALSE);
				else if (!(j == 0 || s[j - 1] == ' '))
					return (FALSE);
			}
			else if (!(s[j] >= '0' && s[j] <= '9') && s[j] != ' ')
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

/*
join_arguments concatenates all the program arguments into a string.

Return value:
- A pointer to the newly allocated string with all arguments joined.
- NULL if the memory allocation fails.
*/

char	*join_arguments(char **argv, int argc)
{
	int		index;
	int		size;
	int		len;
	char	*str;

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

/*
load_list parses a string containing numbers separated by spaces and loads
them into a linked list. It iterates through the strings and detects the
beginning of each number, which converts using valid_atoi.
*/

t_bool	load_list(t_list **list, char *nw_arg)
{
	int		flag;
	int		nbr;
	t_list	*node;

	flag = 0;
	while (*nw_arg != '\0')
	{
		if (((*nw_arg >= '0' && *nw_arg <= '9') || *nw_arg == '-') && flag == 0)
		{
			if (!valid_atoi(nw_arg, &nbr))
				return (FALSE);
			node = ft_create_node(nbr);
			ft_lstadd_back(list, node);
			flag = 1;
			if (*nw_arg == '-')
				nw_arg++;
			while (*nw_arg >= '0' && *nw_arg <= '9')
				nw_arg++;
			continue ;
		}
		else if (*nw_arg == ' ')
			flag = 0;
		nw_arg++;
	}
	return (TRUE);
}

/*
check_duplicates checks whether the list contains any duplicates.
It iterates through each node in the list and compares its value with
all the other nodes.

Return value:
- TRUE if at least one duplicate value is found.
- FALSE if all values are unique.
*/

t_bool	check_duplicates(t_list *list)
{
	t_list	*current;
	t_list	*temp;

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

/*
valid_atoi converts a string to an integer while checking the number
is in the range of an integer. If the conversion is successful, the result
is stored in the variable pointed by nbr.

Return value:
- TRUE if the conversion is valid and within integer limits.
- FALSE if there is an overflow.
*/

t_bool	valid_atoi(const char *nptr, int *nbr)
{
	long	result;
	int		index;
	int		sign;

	result = 0;
	index = 0;
	sign = 1;
	if (nptr[index] == '-')
	{
		sign *= -1;
		index++;
	}
	while (nptr[index] >= '0' && nptr[index] <= '9')
	{
		result = result * 10 + (nptr[index] - '0');
		if (sign == 1 && result > 2147483647)
			return (FALSE);
		if (sign == -1 && (-result) < -2147483648)
			return (FALSE);
		index++;
	}
	*nbr = sign * result;
	return (TRUE);
}
