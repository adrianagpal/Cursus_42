/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:30:51 by adrianag          #+#    #+#             */
/*   Updated: 2025/12/03 20:30:53 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	n;
	char	*ptr;

	ptr = (char *)big;
	n = 0;
	if (little[0] == '\0')
	{
		return (ptr);
	}
	while (big[n] != '\0' && n < len)
	{
		i = 0;
		while (big[n + i] == little[i] && (n + i) < len)
		{
			if (little[i + 1] == '\0')
			{
				return (&ptr[n]);
			}
			i++;
		}
		n++;
	}
	return (0);
}
