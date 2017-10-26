/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuni.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 13:44:20 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/20 13:43:52 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_writelenc(t_struct *t, int n, wint_t d)
{
	int		i;
	char	c;
	int		j;
	char	*str;

	if (d <= 255 && d >= 128)
	{
		n--;
		t->c--;
	}
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

static void		ft_binchar3(t_struct *t, t_conv *p, wint_t n)
{
	unsigned int	v;
	unsigned char	o1;
	unsigned char	o2;
	unsigned char	o3;
	unsigned char	o4;

	v = n;
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

static void		ft_binchar2(t_struct *t, t_conv *p, wint_t n)
{
	unsigned char		o1;
	unsigned char		o2;
	unsigned char		o3;
	unsigned int		v;

	v = n;
	if (p->size <= 16 && MB_CUR_MAX != 1)
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
		ft_binchar3(t, p, n);
}

static void		ft_binchar1(t_struct *t, t_conv *p, wint_t n)
{
	unsigned char		o1;
	unsigned char		o2;
	unsigned int		v;

	p->size = ft_strlen(ft_width(n, 2, t));
	v = n;
	if (p->size <= 7)
	{
		o1 = (char)n;
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
		ft_binchar2(t, p, n);
}

void			ft_puni(va_list ap, t_struct *t, t_conv *p, const char *ft)
{
	wint_t			n;

	p->mask1 = 49280;
	p->mask2 = 14712960;
	p->mask3 = 4034953344;
	t->zero = 0;
	n = va_arg(ap, wint_t);
	if (MB_CUR_MAX == 1 && n > 255)
	{
		t->zero = -1;
		ft_strdel(&t->str);
		return ;
	}
	ft_checknb(ft, t);
	ft_flag(ft, t, t->per);
	if (t->neg == 0 && ft_charlen(n, t) < t->nbl)
		ft_writelenc(t, ft_charlen(n, t), n);
	if (n >= 128 && n <= 255 && MB_CUR_MAX == 1)
		ft_binone(t, p, n);
	else
		ft_binchar1(t, p, n);
	if (t->neg == 1 && ft_charlen(n, t) < t->nbl)
		ft_writelenc(t, ft_charlen(n, t), n);
	ft_strdel(&t->str);
}
