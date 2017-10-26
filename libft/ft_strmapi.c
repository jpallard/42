/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:01:23 by jpallard          #+#    #+#             */
/*   Updated: 2016/11/19 16:04:25 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*str;
	char			*ret;

	i = 0;
	if (s)
	{
		str = (char*)s;
		len = ft_strlen(str);
		ret = (char *)malloc(sizeof(char) * len + 1);
		if (ret == NULL)
			return (NULL);
		while (str[i])
		{
			ret[i] = f(i, str[i]);
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (0);
}
