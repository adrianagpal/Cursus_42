/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:29:30 by adrianag          #+#    #+#             */
/*   Updated: 2025/12/03 20:29:32 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_count_digits(long *digits, long *divisor, int n)
{
	long	dig;
	long	div;

	dig = 0;
	div = 1;
	if (n == 0)
	{
		dig = 1;
		div = 10;
	}
	if (n < 0)
	{
		n *= -1;
		dig++;
	}
	while (n != 0)
	{
		n /= 10;
		div *= 10;
		dig++;
	}
	*digits = dig;
	*divisor = div;
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned char	c;
	long			digits;
	long			divisor;
	long			nbr;

	ft_count_digits(&digits, &divisor, n);
	nbr = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr *= -1;
	}
	while (divisor > 1)
	{
		divisor /= 10;
		c = nbr / divisor + '0';
		write(fd, &c, 1);
		nbr = nbr % divisor;
	}
}
