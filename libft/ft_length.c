/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:17:52 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/16 13:32:01 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_length(const char *ft, t_struct *t, t_conv *p, int per)
{
	int i;

	p->ch = 0;
	p->cl = 0;
	p->j = 0;
	p->z = 0;
	i = per;
	while (ft[i] != t->spe)
	{
		if (ft[i] == 'h')
			p->ch++;
		if (ft[i] == 'l' || t->spe == 'D' || t->spe == 'U' || t->spe == 'O')
			p->cl = 1;
		if (ft[i] == 'j')
			p->j = 1;
		if (ft[i] == 'z')
			p->z = 1;
		i++;
	}
}

void	ft_flag(const char *ft, t_struct *t, int per)
{
	int i;

	i = per;
	t->pos = 0;
	t->neg = 0;
	t->diese = 0;
	t->zero = 0;
	t->space = 0;
	while (ft[i] != t->spe)
	{
		if (ft[i] == '+')
			t->pos = 1;
		if (ft[i] == '-')
			t->neg = 1;
		if (ft[i] == '#')
			t->diese = 1;
		if (ft[i] == '0')
		{
			if (ft_strchr("0123456789", ft[i - 1]) == NULL)
				t->zero = 1;
		}
		if (ft[i] == ' ')
			t->space = 1;
		i++;
	}
}
