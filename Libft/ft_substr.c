/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:31:07 by adrianag          #+#    #+#             */
/*   Updated: 2025/12/03 20:31:09 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		length;
	size_t		index_ptr;
	char		*ptr;

	length = ft_strlen(s);
	index_ptr = 0;
	if (length > start && len >= (length - start))
		len = length - start;
	if (start >= length || length == 0)
		return (ft_strdup(""));
	ptr = ft_calloc(len + 1, 1);
	if (!ptr)
		return (NULL);
	while (s[start] != '\0' && index_ptr < len)
	{
		ptr[index_ptr] = s[start];
		start++;
		index_ptr++;
	}
	ptr[index_ptr] = '\0';
	return (ptr);
}
