/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 11:30:05 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/16 16:43:00 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	base3(va_list ap, t_struct *t, const char *ft, t_conv *p)
{
	char	*str;

	if (t->spe == 'u' || t->spe == 'U')
	{
		if (p->cl == 1)
		{
			str = ft_width(va_arg(ap, unsigned long int), 10, t);
			ft_allinone(ft, t, str);
		}
		else if (p->ch == 1)
		{
			str = ft_width((unsigned short int)va_arg(ap, int), 10, t);
			ft_allinone(ft, t, str);
		}
		else if (p->ch == 2)
		{
			str = ft_width((unsigned char)va_arg(ap, int), 10, t);
			ft_allinone(ft, t, str);
		}
		ft_end3(ap, t, ft, p);
	}
}

void	base2(va_list ap, t_struct *t, const char *ft, t_conv *p)
{
	char	*str;

	if (t->spe == 'o' || t->spe == 'O')
	{
		if (p->cl == 1)
		{
			str = ft_width(va_arg(ap, unsigned long int), 8, t);
			ft_allinone(ft, t, str);
		}
		else if (p->ch == 1)
		{
			str = ft_width((unsigned short int)va_arg(ap, int), 8, t);
			ft_allinone(ft, t, str);
		}
		else if (p->ch == 2)
		{
			str = ft_width((unsigned char)va_arg(ap, int), 8, t);
			ft_allinone(ft, t, str);
		}
		ft_end2(ap, t, ft, p);
	}
}

void	base1(va_list ap, t_struct *t, const char *ft, t_conv *p)
{
	char	*str;

	if (t->spe == 'X')
	{
		if (p->cl == 1)
		{
			str = ft_widthx(va_arg(ap, unsigned long int), 16, t);
			ft_allinone(ft, t, str);
		}
		else if (p->ch == 1)
		{
			str = ft_widthx((unsigned short int)va_arg(ap, int), 16, t);
			ft_allinone(ft, t, str);
		}
		else if (p->ch == 2)
		{
			str = ft_widthx((unsigned char)va_arg(ap, int), 16, t);
			ft_allinone(ft, t, str);
		}
		ft_end1(ap, t, ft, p);
	}
}

void	ft_base(va_list ap, t_struct *t, const char *ft, t_conv *p)
{
	char	*str;

	if (t->spe == 'x')
	{
		if (p->cl == 1)
		{
			str = ft_width(va_arg(ap, unsigned long int), 16, t);
			ft_allinone(ft, t, str);
		}
		else if (p->ch == 1)
		{
			str = ft_width((unsigned short int)va_arg(ap, int), 16, t);
			ft_allinone(ft, t, str);
		}
		else if (p->ch == 2)
		{
			str = ft_width((unsigned char)va_arg(ap, int), 16, t);
			ft_allinone(ft, t, str);
		}
		ft_end(ap, t, ft, p);
	}
}
