/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 01:34:08 by adri              #+#    #+#             */
/*   Updated: 2026/03/10 19:41:19 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			index;

	ptr = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		ptr[index] = (unsigned char)c;
		index++;
	}
	return (ptr);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	if (!dest && !src)
	{
		return (NULL);
	}
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	index = 0;
	while (index < n)
	{
		ptr_dest[index] = ptr_src[index];
		index++;
	}
	return (dest);
}

char	*ft_realloc(char *ptr, size_t size, int n_char)
{
	char	*line;

	line = malloc(sizeof(char) * size);
	if (!line)
		return (NULL);
	if (ptr)
	{
		ft_memcpy(line, ptr, n_char);
		free (ptr);
		ptr = NULL;
	}
	return (line);
}

/*
append_char checks if line capacity allows to copy enough according to the 
line index. For a new line (line index = 0), it will create a dynamically 
allocated string of a given size. If capacity is not enough, it will duplicate
the size of the string. After checking there is enough space to copy, it will 
append a given character. 
*/
char	*append_char(char *ptr, char letter, int *ptr_index, int *capacity)
{
	if (*ptr_index == 0)
	{
		*capacity = 32;
		ptr = ft_realloc(ptr, *capacity + 1, *ptr_index);
	}
	while (*ptr_index > *capacity)
	{
		*capacity *= 2;
		ptr = ft_realloc(ptr, *capacity + 1, *ptr_index);
	}
	ptr[*ptr_index] = letter;
	if (ptr[*ptr_index] != letter)
	{
		return (NULL);
	}
	(*ptr_index)++;
	return (ptr);
}

/*
free_and_set frees the pointer if it was not null, 
and sets all static variables to 0. 
*/
void	free_and_set(char **new_line, int *index, int *bytes, char *temp)
{
	if (*new_line)
	{
		free (*new_line);
		*new_line = NULL;
	}
	ft_memset(temp, 0, BUFFER_SIZE);
	*index = 0;
	*bytes = 0;
}
