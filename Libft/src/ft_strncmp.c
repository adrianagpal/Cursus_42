/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adri <adri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:16:23 by adri              #+#    #+#             */
/*   Updated: 2025/08/20 17:50:47 by adri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int    ft_strncmp(const char *s1, const char *s2, size_t n)   
{
    size_t     index;

    index = 0;
    while (s1[index] != '\0' && index < n)
    {
        /* We cast to unsigned char to handle characters with values > 127 correctly */
        if ((unsigned char)s1[index] != (unsigned char)s2[index])
        {
            return ((unsigned char)s1[index] - (unsigned char)s2[index]);
        }
        index++;
    }
    return 0;
}