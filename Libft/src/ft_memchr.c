/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adri <adri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:16:23 by adri              #+#    #+#             */
/*   Updated: 2025/08/20 21:07:39 by adri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)   
{
    size_t     index;
    /* When dealing with memory, we cast to unsigned char, because we want to treat memory as raw bytes 0–255 */
    unsigned char *ptr = (unsigned char *)s;
    
    index = 0;
    /* Here we do not put ptr != '\0' because we are accessing memory, not null-terminated strings */
    while (index < n)
    {
        if ((unsigned char)ptr[index] == (unsigned char)c)
        {
            return ptr + index;
        }
        index++;
    }
    return NULL;
}