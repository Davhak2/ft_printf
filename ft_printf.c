/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:47:28 by davihako          #+#    #+#             */
/*   Updated: 2025/01/16 17:24:38 by davihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num_len(int num)
{
	int	count;

	if (num == 0)
		return (1);
	count = 0;
	if (num < 0)
		count++;
	while (num)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static int	handle_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static int	handle_str(char *str)
{
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	formats(const char fmt, va_list args)
{
	int	num;

	if (fmt == 'c')
		return (handle_char(va_arg(args, int)));
	else if (fmt == 's')
		return (handle_str(va_arg(args, char *)));
	else if ((fmt == 'i') || (fmt == 'd'))
	{
		num = va_arg(args, int);
		ft_putnbr_fd(num, 1);
		return (ft_num_len(num));
	}
	else if (fmt == 'u')
		return (ft_putnbr_positive(va_arg(args, unsigned int)));
	else if (fmt == 'x' || fmt == 'X')
		return (ft_putnbr_hexodecimal(va_arg(args, unsigned int), fmt));
	else if (fmt == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (fmt == '%')
		return (handle_char('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	int		check;

	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			check = formats(*(++str), args);
			if (check == -1)
				return (-1);
			len += check;
		}
		else
		{
			ft_putchar_fd(*str, 1);
			len++;
		}
		str++;
	}
	va_end(args);
	return (len);
}
