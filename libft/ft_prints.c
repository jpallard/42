/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 12:32:27 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/18 12:39:08 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_puts(t_struct *t, char *tmp, char *ptr)
{
	char *tpp;

	if (t->neg == 1)
	{
		tpp = ft_strjoin(ptr, tmp);
		ft_putstr(tpp);
		t->c = t->c + ft_strlen(tpp);
	}
	else
	{
		tpp = ft_strjoin(tmp, ptr);
		ft_putstr(tpp);
		t->c = t->c + ft_strlen(tpp);
	}
}

void			ft_prints(char *ptr, const char *ft, t_struct *t)
{
	int		i;
	int		j;
	char	*tmp;
	char	c;

	if (t->point == 1)
		ptr = ft_precisions(ft, t, ptr);
	c = ' ';
	j = t->nbl - ft_strlen(ptr);
	if (j > 0)
	{
		i = 0;
		tmp = ft_strnew(j);
		while (i < j)
		{
			tmp[i] = c;
			i++;
		}
		ft_puts(t, tmp, ptr);
	}
	else
	{
		ft_putstr(ptr);
		t->c = t->c + ft_strlen(ptr);
	}
}
