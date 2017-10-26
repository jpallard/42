/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:26:29 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/18 12:46:15 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putc(t_struct *t, char *str, int c)
{
	if (t->neg == 1)
	{
		ft_putchar(c);
		ft_putstr(str);
		t->c = t->c + ft_strlen(str) + 1;
	}
	else
	{
		ft_putstr(str);
		ft_putchar(c);
		t->c = t->c + ft_strlen(str) + 1;
	}
}

void			ft_printc(int c, t_struct *t)
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
		ft_putc(t, str, c);
	}
	else
	{
		ft_putchar(c);
		t->c++;
	}
}
