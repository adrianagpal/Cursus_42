/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:30:23 by adrianag          #+#    #+#             */
/*   Updated: 2025/12/03 20:30:24 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	index_src;
	size_t	index_dst;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	index_src = 0;
	index_dst = dst_len;
	if (size < dst_len + 1)
	{
		return (src_len + size);
	}
	while ((size - index_dst - 1 > 0) && src[index_src] != '\0')
	{
		dst[index_dst] = src[index_src];
		index_dst++;
		index_src++;
	}
	dst[index_dst] = '\0';
	return (dst_len + src_len);
}
