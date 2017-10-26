/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:42:05 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/26 15:26:05 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		str = (char*)malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			exit(EXIT_FAILURE);
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		return (str);
	}
	return (0);
}
