/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:44:20 by jpallard          #+#    #+#             */
/*   Updated: 2016/11/18 12:12:40 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const	char		*str;
	char				*dest;
	size_t				i;

	i = 0;
	str = (const char*)src;
	dest = (char *)dst;
	while (i < n)
	{
		dest[i] = str[i];
		if (dest[i] == c)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
