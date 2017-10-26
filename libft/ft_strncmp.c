/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:55:54 by jpallard          #+#    #+#             */
/*   Updated: 2016/11/19 16:03:46 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 && (*s1 == *s2) && n)
	{
		s1++;
		s2++;
		--n;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
