/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:29:46 by adrianag          #+#    #+#             */
/*   Updated: 2026/05/06 15:54:17 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int	index;
	int	new_word;
	int	nbr_words;

	index = 0;
	nbr_words = 0;
	new_word = 1;
	while (s[index] != '\0')
	{
		if (s[index] != c && (index == 0 || new_word == 1))
		{
			nbr_words++;
			new_word = 0;
		}
		if (s[index] == c)
		{
			new_word = 1;
		}
		index++;
	}
	return (nbr_words);
}

static char	*ft_fill_word(char const *s, char c, int *index)
{
	char	*ptr;
	int		length;
	int		start;

	start = *index;
	length = 0;
	while (s[start] != '\0' && s[start] != c)
	{
		length++;
		start++;
	}
	ptr = malloc(sizeof(char) * (length + 1));
	if (!ptr)
	{
		return (NULL);
	}
	ft_strlcpy(ptr, &s[*index], length + 1);
	*index = start - 1;
	return (ptr);
}

static void	*ft_free_ptr(char **ptr)
{
	while (*ptr)
	{
		free (*ptr);
		ptr++;
	}
	return (NULL);
}

static char	**ft_fill_array(const char *s, char **ptr, char c)
{
	int		index;
	int		index_ptr;

	index = 0;
	index_ptr = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c)
		{
			ptr[index_ptr] = ft_fill_word(s, c, &index);
			if (!ptr[index_ptr])
			{
				return (ft_free_ptr(ptr));
			}
			index_ptr++;
		}
		index++;
	}
	ptr[index_ptr] = 0;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	char	**res;

	ptr = ft_calloc((ft_word_count(s, c) + 1), sizeof(char *));
	if (!ptr)
	{
		return (NULL);
	}
	res = ft_fill_array(s, ptr, c);
	if (!res)
	{
		free (ptr);
		return (NULL);
	}
	return (res);
}

#include <stdio.h>

int	main(void)
{
	char const *s = "Hola me llamo Adri";
	char **res = ft_split(s, 'p');

	while(*res)
	{
		printf("%s\n", *res);
		res++;
	}
	
}
