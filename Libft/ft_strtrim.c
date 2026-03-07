/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:31:02 by adrianag          #+#    #+#             */
/*   Updated: 2025/12/03 20:31:04 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_start_index(char const *s1, char const *set)
{
	int	index_start;

	index_start = 0;
	while (s1[index_start] != '\0')
	{
		if (ft_strchr(set, s1[index_start]) == NULL)
		{
			return (index_start);
		}
		index_start++;
	}
	return (index_start - 1);
}

static int	ft_get_end_index(char const *s1, char const *set)
{
	size_t	str_len;

	str_len = ft_strlen(s1);
	while (str_len > 0)
	{
		if (ft_strchr(set, s1[str_len - 1]) == NULL)
		{
			return (str_len - 1);
		}
		str_len--;
	}
	return (str_len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		index;
	int		index_start;
	int		index_end;
	int		length;

	index = 0;
	index_start = ft_get_start_index(s1, set);
	index_end = ft_get_end_index(s1, set);
	length = index_end - index_start + 1;
	if (length < 0 || index_start == -1)
		length = 0;
	new_str = malloc(sizeof(char) * (length + 1));
	if (!new_str)
		return (NULL);
	while (length > 0)
	{
		new_str[index] = s1[index_start];
		index++;
		index_start++;
		length--;
	}
	new_str[index] = 0;
	return (new_str);
}
