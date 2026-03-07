/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adri <adri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:16:23 by adri              #+#    #+#             */
/*   Updated: 2025/08/19 16:58:08 by adri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcat(char *dest, const char *src, size_t buffer)   
{
    size_t     index;
    size_t     srcsize;
    size_t     destsize;

    index = 0;
    destsize = ft_strlen(dest);
    srcsize = ft_strlen(src);
    if (buffer <= destsize)
        return buffer + srcsize;
    while (destsize + index < buffer - 1 && src[index] != '\0')
    {
        dest[destsize + index] = src[index];
        index++;
    }
    dest[destsize + index] = '\0';

    return srcsize + destsize;
}