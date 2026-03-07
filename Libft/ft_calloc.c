/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:27:04 by adrianag          #+#    #+#             */
/*   Updated: 2025/12/03 20:27:06 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			index;

	index = 0;
	ptr = malloc(size * nmemb);
	if (!ptr)
	{
		return (NULL);
	}
	while (index < nmemb * size)
	{
		ptr[index] = 0;
		index++;
	}
	return (ptr);
}
