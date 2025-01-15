/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:45:33 by davihako          #+#    #+#             */
/*   Updated: 2025/01/15 19:27:55 by davihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char	*str, ...);
int	ft_putnbr_positive(long n);
int	ft_putnbr_hexodecimal(unsigned long nbr, char format);
int	ft_putptr(void *ptr);

#endif
