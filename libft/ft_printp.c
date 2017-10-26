/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 15:56:27 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/18 12:47:19 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_putp(t_struct *t, char *tmp, char *adr)
{
	if (t->neg == 1)
	{
		write(1, "0x", 2);
		ft_putstr(adr);
		ft_putstr(tmp);
		t->c = t->c + ft_strlen(tmp) + ft_strlen(adr) + 2;
	}
	else
	{
		ft_putstr(tmp);
		write(1, "0x", 2);
		ft_putstr(adr);
		t->c = t->c + ft_strlen(tmp) + ft_strlen(adr) + 2;
	}
}

static void		ft_witness(char *adr, t_struct *t)
{
	int		i;
	int		j;
	char	*tmp;
	char	c;

	c = ' ';
	j = t->nbl - ft_strlen(adr) - 2;
	if (j > 0)
	{
		i = 0;
		tmp = ft_strnew(j);
		while (i < j)
		{
			tmp[i] = c;
			i++;
		}
		ft_putp(t, tmp, adr);
	}
	else
	{
		write(1, "0x", 2);
		ft_putstr(adr);
		t->c = t->c + 2 + ft_strlen(adr);
	}
}

void			ft_printp(void *ptr, t_struct *t)
{
	unsigned long int	n;
	char				*str;

	if (ptr == NULL)
	{
		ft_witness("0", t);
		return ;
	}
	n = (unsigned long int)ptr;
	str = ft_width(n, 16, t);
	ft_witness(str, t);
	ft_strdel(&t->str);
}
