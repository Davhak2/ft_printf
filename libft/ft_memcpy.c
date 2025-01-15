/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davihako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:41:58 by davihako          #+#    #+#             */
/*   Updated: 2025/01/14 16:00:33 by davihako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	len;
	char	*src1;
	char	*dest1;

	len = -1;
	src1 = (char *)src;
	dest1 = (char *)dest;
	while (++len < n)
		dest1[len] = src1[len];
	return (dest);
}
