/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 12:02:32 by jpallard          #+#    #+#             */
/*   Updated: 2017/06/24 12:09:47 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_specifier3(const char *ft, va_list ap, int i, t_struct *t)
{
	t_conv	*p;

	p = ft_memalloc(sizeof(t_conv));
	if (ft[i] == 'C')
	{
		p->exe = 0;
		ft_puni(ap, t, p, ft);
	}
	if (ft[i] == 'S')
		ft_pus(ap, t, p, ft);
	ft_memdel((void*)&p);
}

static void		ft_specifier2(const char *ft, va_list ap, int i, t_struct *t)
{
	void	*ptr;
	t_conv	*p;

	p = ft_memalloc(sizeof(t_conv));
	t->spe = ft[i];
	if (ft[i] == 'x' || ft[i] == 'X' || ft[i] == 'o' || ft[i] == 'u' || ft[i]
			== 'U' || ft[i] == 'O')
	{
		ft_length(ft, t, p, t->per);
		ft_flag(ft, t, t->per);
		ft_checknb(ft, t);
		ft_base(ap, t, ft, p);
		base1(ap, t, ft, p);
		base2(ap, t, ft, p);
		base3(ap, t, ft, p);
	}
	if (ft[i] == 'p')
	{
		ptr = va_arg(ap, void *);
		ft_flag(ft, t, t->per);
		ft_checknb(ft, t);
		ft_printp(ptr, t);
	}
	ft_memdel((void*)&p);
}

static void		ft_specifier(const char *ft, va_list ap, int i, t_struct *t)
{
	t_conv	*p;

	p = ft_memalloc(sizeof(t_conv));
	t->spe = ft[i];
	if (ft[i] == '%')
	{
		ft_checknb(ft, t);
		t->per = t->per + 1;
		ft_flag(ft, t, t->per);
		ft_printper(t);
	}
	if (ft[i] == 'i' || ft[i] == 'd' || ft[i] == 'c' || ft[i] == 'D')
		ft_sped(ft, ap, t, p);
	ft_spec(ft, ap, t, p);
	ft_memdel((void*)&p);
}

static int		ft_specf(const char *ft, va_list ap, int i, t_struct *t)
{
	if (ft[i])
	{
		i++;
		while (ft_strchr("sSpdDioOuUxXcC%", ft[i]) == NULL && ft[i])
			i++;
		ft_specifier(ft, ap, i, t);
		ft_specifier2(ft, ap, i, t);
		ft_specifier3(ft, ap, i, t);
	}
	return (i);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	int			i;
	t_struct	*t;
	int			count;

	i = 0;
	t = ft_memalloc(sizeof(t_struct));
	t->c = 0;
	t->per = 0;
	va_start(ap, format);
	while (format[i])
	{
		i = ft_chara(format, i, t);
		i = ft_specf(format, ap, i, t);
		if (format[i] == '\0')
			break ;
		if (t->zero == -1)
			return (ft_error(t));
		i++;
	}
	va_end(ap);
	count = t->c;
	ft_memdel((void*)&t);
	return (count);
}
