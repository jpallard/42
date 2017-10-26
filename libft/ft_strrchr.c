/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 12:48:04 by jpallard          #+#    #+#             */
/*   Updated: 2016/11/23 15:16:07 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*str;
	size_t			len;
	size_t			i;

	str = (unsigned char *)s;
	len = ft_strlen(s);
	i = len;
	while (str[i - 1])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i--;
	}
	if (str[i] == (unsigned char)c)
		return ((char *)&str[i]);
	return (0);
}
