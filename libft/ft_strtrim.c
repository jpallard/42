/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 14:06:02 by jpallard          #+#    #+#             */
/*   Updated: 2016/11/24 14:16:24 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char				*str;
	size_t				len;
	size_t				i;
	unsigned int		debut;

	i = 0;
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		debut = i;
		if (s[i] == '\0')
			return (ft_strnew(1));
		i = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i--;
		len = i - debut;
		str = ft_strsub(s, debut, len + 1);
		return (str);
	}
	return (0);
}
