/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuni.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 13:44:20 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/20 13:44:15 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_writelen(t_struct *t, int n)
{
	int		i;
	char	c;
	int		j;
	char	*str;

	i = t->nbl - n;
	c = ' ';
	j = 0;
	str = ft_strnew(i);
	while (i)
	{
		str[j] = c;
		j++;
		i--;
	}
	ft_putstr(str);
	t->c = t->c + ft_strlen(str);
}

static void		ft_bin3(t_struct *t, t_conv *p, int i, wchar_t *str)
{
	unsigned int	v;
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	o4;

	v = str[i];
	o4 = (v << 26) >> 26;
	o3 = ((v >> 6) << 26) >> 26;
	o2 = ((v >> 12) << 26) >> 26;
	o1 = ((v >> 18) << 29) >> 29;
	v = (p->mask3 >> 24) | o1;
	write(1, &v, 1);
	v = ((p->mask3 << 8) >> 24) | o2;
	write(1, &v, 1);
	v = ((p->mask3 << 16) >> 24) | o3;
	write(1, &v, 1);
	v = ((p->mask3 << 24) >> 24) | o4;
	write(1, &v, 1);
	t->c = t->c + 4;
}

static void		ft_bin2(t_struct *t, t_conv *p, int i, wchar_t *str)
{
	unsigned char		o1;
	unsigned char		o2;
	unsigned char		o3;
	unsigned int		v;

	v = str[i];
	if (p->size <= 16)
	{
		o3 = (v << 26) >> 26;
		o2 = ((v >> 6) << 26) >> 26;
		o1 = ((v >> 12) << 28) >> 28;
		v = (p->mask2 >> 16) | o1;
		write(1, &v, 1);
		v = ((p->mask2 << 16) >> 24) | o2;
		write(1, &v, 1);
		v = ((p->mask2 << 24) >> 24) | o3;
		write(1, &v, 1);
		t->c = t->c + 3;
	}
	else
		ft_bin3(t, p, i, str);
}

static void		ft_bin1(t_struct *t, t_conv *p, int i, wchar_t *str)
{
	unsigned char		o1;
	unsigned char		o2;
	unsigned int		v;

	p->size = ft_strlen(ft_width(str[i], 2, t));
	v = str[i];
	if (p->size <= 7)
	{
		o1 = str[i];
		write(1, &o1, 1);
		t->c++;
	}
	else if (p->size <= 11)
	{
		o2 = (v << 26) >> 26;
		o1 = ((v >> 6) << 27) >> 27;
		v = (p->mask1 >> 8) | o1;
		write(1, &v, 1);
		v = ((p->mask1 << 24) >> 24) | o2;
		write(1, &v, 1);
		t->c = t->c + 2;
	}
	else
		ft_bin2(t, p, i, str);
}

void			ft_pus(va_list ap, t_struct *t, t_conv *p, const char *ft)
{
	int				i;
	wchar_t			*str;

	p->mask1 = 49280;
	p->mask2 = 14712960;
	p->mask3 = 4034953344;
	i = 0;
	str = va_arg(ap, wchar_t*);
	if (!str)
		return (ft_wcharnul(t));
	ft_checknb(ft, t);
	ft_flag(ft, t, t->per);
	if (t->neg == 0 && ft_wstrlen(str, t) < t->nbl)
		ft_writelen(t, ft_wstrlen(str, t));
	while (str[i])
	{
		ft_bin1(t, p, i, str);
		i++;
	}
	if (t->neg == 1 && ft_wstrlen(str, t) < t->nbl)
		ft_writelen(t, ft_wstrlen(str, t));
	ft_strdel(&t->str);
}
