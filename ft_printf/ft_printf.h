/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrianag <adrianag@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:07:24 by adrianag          #+#    #+#             */
/*   Updated: 2026/02/16 16:45:46 by adrianag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putstr(char *str, int *count);
void	ft_putnbr_unsigned(unsigned int nbr, int *count);
void	ft_putnbr(long nbr, int *count);
void	ft_putnbr_hex(unsigned long nbr, char lower, int *count);
void	ft_putptr(void *address, int *count);
int		ft_printf(char const *format, ...);

#endif
