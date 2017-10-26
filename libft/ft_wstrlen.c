/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 12:08:40 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/18 12:44:03 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wstrlen(wchar_t *s, t_struct *t)
{
	int	i;
	int	size;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		size = ft_strlen(ft_width(s[i], 2, t));
		if (size <= 7)
			j++;
		else if (size <= 11)
			j = j + 2;
		else if (size <= 16)
			j = j + 3;
		else
			j = j + 4;
		i++;
	}
	return (j);
}

int		ft_charlen(wint_t c, t_struct *t)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strlen(ft_width(c, 2, t));
	if (size <= 7)
		i = 1;
	else if (size <= 11)
		i = 2;
	else if (size <= 16)
		i = 3;
	else
		i = 4;
	return (i);
}
