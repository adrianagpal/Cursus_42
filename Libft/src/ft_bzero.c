/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adri <adri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:16:23 by adri              #+#    #+#             */
/*   Updated: 2025/08/15 14:47:16 by adri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_bzero(void *ptr, size_t n)
{
    size_t     index;
    unsigned char    *p = (unsigned char*)ptr;

    index = 0;
    while (index < n)
    {
        /* 0 and '\0' are equivalent to represent null / zero byte */
        p[index] = 0;
        index++; 
    }
    return ptr;
}

