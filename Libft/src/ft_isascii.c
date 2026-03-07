/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adri <adri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:28:47 by adri              #+#    #+#             */
/*   Updated: 2025/08/12 12:31:46 by adri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Checks that an unsigned character is less than 127 */
int    ft_isascii(unsigned char c)
{
    /* No need to include => 0, as it is always True because unsigned char is always between 0 and 255 */
    if (c <= 127)
    {
        return 1;
    }
    return 0;
}
