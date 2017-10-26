/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:22:56 by jpallard          #+#    #+#             */
/*   Updated: 2016/11/19 16:01:00 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*dest;
	char			*str;
	size_t			i;

	dest = (char*)dst;
	str = (char*)src;
	if (str < dest)
	{
		i = len;
		while (i > 0)
		{
			dest[i - 1] = str[i - 1];
			i--;
		}
	}
	else if (dest < str)
		ft_memcpy(dest, str, len);
	return (dst);
}
