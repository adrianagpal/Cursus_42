/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adri <adri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 01:34:08 by adri              #+#    #+#             */
/*   Updated: 2026/03/07 01:34:27 by adri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char    *ft_realloc(char *ptr, size_t size, int n_char)
{
    char    *line;

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

char    *append_char(char *ptr, char letter, int *ptr_index, int *capacity)
{
    if (*ptr_index == 0)
    {
        *capacity = 32;
        ptr = ft_realloc(ptr, *capacity + 1, *ptr_index);
    }   
    if (*ptr_index > *capacity)
    {
        *capacity *= 2;
        ptr = ft_realloc(ptr, *capacity + 1, *ptr_index);
    }
    ptr[*ptr_index] = letter;
    (*ptr_index)++;

    return (ptr);
}