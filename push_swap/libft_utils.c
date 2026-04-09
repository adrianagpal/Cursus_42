/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:51:59 by username          #+#    #+#             */
/*   Updated: 2026/04/09 16:03:33 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	if (!dest && !src)
	{
		return (NULL);
	}
	ptr_dest = (unsigned char *) dest;
	ptr_src = (unsigned char *) src;
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
		free(ptr);
		ptr = NULL;
	}
	return (line);
}

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
