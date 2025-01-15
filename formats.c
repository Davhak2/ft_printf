/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:47:51 by davihako          #+#    #+#             */
/*   Updated: 2025/01/15 19:47:14 by davihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_positive(long n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putnbr_positive(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
	len++;
	return (len);
}

int	ft_putnbr_hexodecimal(unsigned long nbr, char format)
{
	int		len;
	char	*base;

	len = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr >= 16)
		len += ft_putnbr_hexodecimal(nbr / 16, format);
	ft_putchar_fd(base[nbr % 16], 1);
	len++;
	return (len);
}

int	ft_putptr(void *ptr)
{
	int	len;

	len = 0;
	if (!ptr)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	ft_putstr_fd("0x", 1);
	len += 2;
	len += ft_putnbr_hexodecimal((unsigned long)ptr, 'x');
	return (len);
}
