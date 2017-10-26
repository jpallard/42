/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:22:24 by jpallard          #+#    #+#             */
/*   Updated: 2016/11/24 13:54:57 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*str;
	char	*ret;
	int		i;

	i = 0;
	if (s)
	{
		len = ft_strlen(s);
		str = (char *)s;
		ret = (char *)malloc(sizeof(char) * len + 1);
		if (ret == NULL)
			return (0);
		while (str[i])
		{
			ret[i] = f(str[i]);
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (0);
}
