/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:38:53 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/18 12:38:26 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putper(t_struct *t, char *str)
{
	if (t->neg == 1)
	{
		ft_putchar('%');
		ft_putstr(str);
		t->c = t->c + ft_strlen(str) + 1;
	}
	else
	{
		ft_putstr(str);
		ft_putchar('%');
		t->c = t->c + ft_strlen(str) + 1;
	}
}

void			ft_printper(t_struct *t)
{
	int		j;
	int		i;
	char	*str;
	char	d;

	d = ' ';
	j = (t->nbl - 1);
	if (j > 0)
	{
		i = 0;
		str = ft_strnew(j);
		while (i < j)
		{
			str[i] = d;
			i++;
		}
		ft_putper(t, str);
	}
	else
	{
		ft_putchar('%');
		t->c++;
	}
}
