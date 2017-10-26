/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:52:53 by jpallard          #+#    #+#             */
/*   Updated: 2016/11/22 11:11:47 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char *s1;
	char *s2;

	if (*little == '\0')
		return ((char*)big);
	while (*big)
	{
		s1 = (char*)little;
		s2 = (char*)big;
		while (*big && *s1 && *big == *s1)
		{
			big++;
			s1++;
		}
		if (!*s1)
			return (s2);
		big = s2 + 1;
	}
	return (0);
}
