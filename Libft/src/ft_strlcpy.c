/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adri <adri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:16:23 by adri              #+#    #+#             */
/*   Updated: 2025/08/18 22:13:25 by adri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcpy(char *dest, const char *src, size_t buffer)   
{
    size_t     index;
    size_t     srcsize;

    index = 0;
    srcsize = ft_strlen(src);
    if (buffer == 0)
        return srcsize;
    while (index < buffer - 1 && src[index] != '\0')
    {
        dest[index] = src[index];
        index++;
    }
    dest[index] = '\0';

    return srcsize;
}