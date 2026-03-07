/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:30:16 by adrianag          #+#    #+#             */
/*   Updated: 2025/12/03 20:30:17 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index_s1;
	int		index_s2;
	int		total_len;
	char	*new_str;

	index_s1 = 0;
	index_s2 = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!new_str)
		return (NULL);
	while (s1[index_s1] != '\0')
	{
		new_str[index_s1] = s1[index_s1];
		index_s1++;
	}
	while (s2[index_s2] != '\0')
	{
		new_str[index_s1] = s2[index_s2];
		index_s1++;
		index_s2++;
	}
	new_str[index_s1] = '\0';
	return (new_str);
}
