/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 10:04:11 by jpallard          #+#    #+#             */
/*   Updated: 2016/11/23 11:53:15 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s)
	{
		str = ft_strnew(len);
		if (str == NULL)
			return (0);
		while (i < len)
		{
			str[i] = s[start];
			i++;
			start++;
		}
		return (str);
	}
	return (0);
}
