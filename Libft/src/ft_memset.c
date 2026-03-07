/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adri <adri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:16:23 by adri              #+#    #+#             */
/*   Updated: 2025/08/15 14:39:53 by adri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Void* is a generic pointer and we don't know the data type (and thus size or structure) it points to.
Therefore, to use the pointed value, we have to cast it. */
void *ft_memset(void *ptr, int x, size_t n)
{
    size_t     index;
    /* We save in p the memory address of the first, so it points to the same address. */
    /* *p and p[0] is the same */
    unsigned char    *p = (unsigned char*)ptr;

    index = 0;
    while (index < n)
    {
        p[index] = (unsigned char)x;
        index++; 
    }
    return ptr;
}

/* Every time a string literal is declared, for example "hola", 
   it is stored by the compiler in a read-only section of memory (.rodata).
   We can use it directly via a pointer (char *p = "hola"), in which case
   the pointer refers to that read-only location. Alternatively, we can 
   initialize an array (char p[5] = "hola"), in which case the literal's 
   contents are copied into the array, allowing them to be modified afterwards. */
