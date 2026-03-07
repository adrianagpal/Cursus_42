/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adri <adri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:16:23 by adri              #+#    #+#             */
/*   Updated: 2025/08/19 18:00:38 by adri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strchr(const char *s, int c)   
{
    int     index;

    index = 0;
    while (s[index] != '\0')
    {
        if (s[index] == c)
        {
            return (char *)(s + index);
        }
        index++;
    }
    /* If c is specified as '\0', the function return a pointer to the terminator */
    if (c == '\0')
        return (char *)(s + index);
    return NULL;
}