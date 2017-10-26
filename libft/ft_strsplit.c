/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 17:02:45 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/26 15:25:30 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_mot_c(const char *s, char c)
{
	int i;
	int mot;

	mot = 0;
	i = 0;
	while (*s)
	{
		if (mot == 1 && *s == c)
			mot = 0;
		if (mot == 0 && *s != c)
		{
			mot = 1;
			i++;
		}
		s++;
	}
	return (i);
}

static int		lettre(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(const char *s, char c)
{
	char		**str;
	int			nb_mot;
	int			i;

	if (s)
	{
		i = 0;
		nb_mot = ft_mot_c((const char *)s, c);
		str = (char**)malloc(sizeof(*str) * (ft_mot_c((const char*)s, c) + 1));
		if (str == NULL)
			exit(EXIT_FAILURE);
		while (nb_mot--)
		{
			while (*s == c && *s)
				s++;
			str[i] = ft_strsub((const char*)s, 0, lettre((const char*)s, c));
			if (str[i] == NULL)
				exit(EXIT_FAILURE);
			s = s + lettre(s, c);
			i++;
		}
		str[i] = NULL;
		return (str);
	}
	return (0);
}
