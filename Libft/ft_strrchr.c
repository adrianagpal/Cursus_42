/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:30:57 by adrianag          #+#    #+#             */
/*   Updated: 2025/12/03 20:30:59 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		str_len;
	char	*ptr;

	str_len = ft_strlen(s);
	ptr = (char *)s;
	while (str_len >= 0)
	{
		if (s[str_len] == (unsigned char)c)
		{
			return (&ptr[str_len]);
		}
		str_len--;
	}
	return (NULL);
}
