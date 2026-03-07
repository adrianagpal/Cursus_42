/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:30:06 by adrianag          #+#    #+#             */
/*   Updated: 2025/12/03 20:30:07 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	index;
	size_t	index_ptr;

	index = 0;
	index_ptr = 0;
	ptr = ft_calloc(ft_strlen(s) + 1, 1);
	if (!ptr)
	{
		return (NULL);
	}
	while (s[index] != '\0')
	{
		ptr[index_ptr] = s[index];
		index_ptr++;
		index++;
	}
	ptr[index_ptr] = '\0';
	return (ptr);
}
