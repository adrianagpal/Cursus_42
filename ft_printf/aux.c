/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:07:14 by adrianag          #+#    #+#             */
/*   Updated: 2026/02/16 16:53:22 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *count)
{
	int	index;

	index = 0;
	if (!str)
	{
		*count = write(1, "(null)", 6);
	}
	else
	{
		while (str[index] != '\0')
		{
			write(1, &str[index], 1);
			index++;
		}
		*count = index;
	}
}

void	ft_putnbr_unsigned(unsigned int nbr, int *count)
{
	if (nbr > 9)
	{
		ft_putnbr_unsigned(nbr / 10, count);
	}
	nbr = nbr % 10 + '0';
	*count += write(1, &nbr, 1);
}

void	ft_putnbr(long nbr, int *count)
{
	if (nbr < 0)
	{
		nbr *= -1;
		*count += write(1, "-", 1);
	}
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10, count);
	}
	nbr = nbr % 10 + '0';
	*count += write(1, &nbr, 1);
}

void	ft_putnbr_hex(unsigned long nbr, char lower, int *count)
{
	int		module;
	int		index;
	char	*str;

	if (lower == 'x')
		str = "abcdef";
	if (lower == 'X')
		str = "ABCDEF";
	if (nbr / 16 > 0)
		ft_putnbr_hex(nbr / 16, lower, count);
	module = nbr % 16;
	if (module >= 0 && module < 10)
	{
		module += '0';
		*count += write(1, &module, 1);
	}
	if (module >= 10 && module < 16)
	{
		index = module % 10;
		*count += write(1, &str[index], 1);
	}
}

void	ft_putptr(void *address, int *count)
{
	unsigned long	m_address;

	m_address = (unsigned long)address;
	if (!m_address)
	{
		*count += (write(1, "(nil)", 5));
	}
	else
	{
		*count += write(1, "0x", 2);
		ft_putnbr_hex(m_address, 'x', count);
	}
}
