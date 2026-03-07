/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adri <adri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:16:23 by adri              #+#    #+#             */
/*   Updated: 2025/08/20 12:45:21 by adri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *s, int c)   
{
    int     index;
    const char  *last;
    int     flag;

    index = 0;
    flag = 0;
    while (s[index] != '\0')
    {
        if (s[index] == c)
        {
            flag = 1;
            last = s + index;
        }
        index++;
    }
    
    if (flag == 1)
        return (char *)last;
    /* If c is specified as '\0', the function return a pointer to the terminator */
    if (c == '\0')
        return (char *)(s + index);
    return NULL;
}