/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adri <adri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:16:23 by adri              #+#    #+#             */
/*   Updated: 2025/08/20 21:46:19 by adri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *big, const char *little, size_t len)   
{
    size_t      index;
    size_t      index_big;

    index = 0;
    index_big = 0;
    if (little == "")
        return (char *)big;

    while (big[index_big + index] != '\0' && little[index] != '\0' && index < len)
    {
        if (big[index_big + index] != little[index])
        {
            index_big++;
            index = 0;
        }
        else
        {
            index++;
        }
    }
    return NULL;
}