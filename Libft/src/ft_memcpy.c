/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adri <adri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:16:23 by adri              #+#    #+#             */
/*   Updated: 2025/08/18 20:27:05 by adri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t     index;
    unsigned char   *a = (unsigned char*)dest;
    unsigned char   *b = (unsigned char*)src;

    index = 0;

    /* Checking for memory overlap */
    if ((a + n <= b) || (a >= b + n))
    {
        while (index < n)
        {
            a[index] = b[index];
            index++;
        }
    }
    return dest;
}