/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:58:16 by jpallard          #+#    #+#             */
/*   Updated: 2016/11/23 14:17:35 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;
	size_t	j;

	j = 0;
	if (*lit == '\0')
		return ((char*)big);
	while (*big && j < len)
	{
		i = 0;
		s1 = (char*)big;
		s2 = (char*)lit;
		while (*big && *s2 && *big == *s2 && i + j < len)
		{
			big++;
			s2++;
			i++;
		}
		if (!*s2)
			return (s1);
		big = s1 + 1;
		j++;
	}
	return (0);
}
