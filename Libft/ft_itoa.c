/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:27:53 by adrianag          #+#    #+#             */
/*   Updated: 2025/12/03 20:27:56 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_count_digits(long n, long *abs_nbr, long *digits, long *divisor)
{
	int		n_digits;
	long	div;

	n_digits = 0;
	div = 1;
	if (n < 0)
	{
		n = -n;
		n_digits++;
	}
	*abs_nbr = n;
	if (n == 0)
	{
		n_digits = 1;
		div = 10;
	}
	while (n > 0)
	{
		n /= 10;
		div *= 10;
		n_digits++;
	}
	*digits = n_digits;
	*divisor = div;
}

char	*ft_itoa(int n)
{
	int		index;
	long	divisor;
	long	digits;
	long	nbr;
	char	*ptr;

	index = 0;
	ft_count_digits((long)n, &nbr, &digits, &divisor);
	ptr = (char *) malloc(sizeof(char) * (digits + 1));
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		ptr[index] = '-';
		index++;
	}
	while (divisor > 1)
	{
		divisor /= 10;
		ptr[index] = (nbr / divisor + '0');
		nbr = nbr % divisor;
		index++;
	}
	ptr[index] = '\0';
	return (ptr);
}
