/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adri <adri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:45:50 by adri              #+#    #+#             */
/*   Updated: 2025/08/18 22:11:40 by adri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* size_t is an unsigned integer data type, which is standard to represent object sizes in memory and count elements */
size_t		ft_strlen(const char *str)
{
	size_t		index;
	
	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return index;
}