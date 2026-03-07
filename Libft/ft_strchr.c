/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:30:01 by adrianag          #+#    #+#             */
/*   Updated: 2025/12/03 20:30:02 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		index;
	char	*ptr;

	index = 0;
	ptr = (char *)s;
	while (s[index] != '\0')
	{
		if (s[index] == (unsigned char)c)
		{
			return (&ptr[index]);
		}
		index++;
	}
	if ((unsigned char)c == '\0')
	{
		return (&ptr[index]);
	}
	return (0);
}
