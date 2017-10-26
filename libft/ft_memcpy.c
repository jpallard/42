/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:31:02 by jpallard          #+#    #+#             */
/*   Updated: 2016/11/16 16:40:23 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char			*str;
	char				*dest;
	size_t				i;

	i = 0;
	str = src;
	dest = dst;
	while (i < n)
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}
