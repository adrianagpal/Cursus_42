/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adri <adri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:16:23 by adri              #+#    #+#             */
/*   Updated: 2025/08/20 21:32:16 by adri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int    ft_memcmp(const void *s1, const void *s2, size_t n)   
{
    size_t     index;
    unsigned char *ptr1 = (unsigned char *)s1;
    unsigned char *ptr2 = (unsigned char *)s2;
    
    index = 0;
    while (index < n)
    {
        if (ptr1[index] > ptr2[index])
        {
            return 1;
        }
        if (ptr1[index] < ptr2[index])
        {
            return -1;
        }
        index++;
    }
    return 0;
}