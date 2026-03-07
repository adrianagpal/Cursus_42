/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:07:09 by adrianag          #+#    #+#             */
/*   Updated: 2026/02/17 13:30:40 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	return_argument(char format, va_list args)
{
	char	c;
	int		count;

	count = 0;
	if (format == 'c')
	{
		c = (char)va_arg(args, int);
		count = write(1, &c, 1);
	}
	else if (format == 's')
		ft_putstr(va_arg(args, char *), &count);
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), &count);
	else if (format == 'u')
		ft_putnbr_unsigned(va_arg(args, int), &count);
	else if (format == 'x')
		ft_putnbr_hex(va_arg(args, unsigned int), format, &count);
	else if (format == 'X')
		ft_putnbr_hex(va_arg(args, unsigned int), format, &count);
	else if (format == 'p')
		ft_putptr(va_arg(args, void *), &count);
	else if (format == '%')
		count = write(1, "%", 1);
	return (count);
}

int	ft_printf(char const *format, ...)
{
	int		index;
	int		count;
	va_list	args;

	index = 0;
	count = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (format[index] != '\0')
	{
		if (format[index] == '%' && format[index + 1] != '\0')
		{
			count += return_argument(format[index + 1], args);
			index++;
		}
		else
		{
			count += write(1, &format[index], 1);
		}
		index++;
	}
	va_end(args);
	return (count);
}
