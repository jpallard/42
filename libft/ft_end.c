/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 12:25:48 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/16 16:45:00 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_end(va_list ap, t_struct *t, const char *ft, t_conv *p)
{
	char *str;

	if (p->cl == 0 && p->ch == 0)
	{
		if (p->z == 1)
		{
			str = ft_width(va_arg(ap, size_t), 16, t);
			ft_allinone(ft, t, str);
		}
		else if (p->j == 1)
		{
			str = ft_width(va_arg(ap, intmax_t), 16, t);
			ft_allinone(ft, t, str);
		}
		else
		{
			str = ft_width(va_arg(ap, unsigned int), 16, t);
			ft_allinone(ft, t, str);
		}
	}
}

void	ft_end1(va_list ap, t_struct *t, const char *ft, t_conv *p)
{
	char *str;

	if (p->cl == 0 && p->ch == 0)
	{
		if (p->z == 1)
		{
			str = ft_widthx(va_arg(ap, size_t), 16, t);
			ft_allinone(ft, t, str);
		}
		else if (p->j == 1)
		{
			str = ft_widthx(va_arg(ap, intmax_t), 16, t);
			ft_allinone(ft, t, str);
		}
		else
		{
			str = ft_widthx(va_arg(ap, unsigned int), 16, t);
			ft_allinone(ft, t, str);
		}
	}
}

void	ft_end2(va_list ap, t_struct *t, const char *ft, t_conv *p)
{
	char *str;

	if (p->cl == 0 && p->ch == 0)
	{
		if (p->z == 1)
		{
			str = ft_width(va_arg(ap, size_t), 8, t);
			ft_allinone(ft, t, str);
		}
		else if (p->j == 1)
		{
			str = ft_width(va_arg(ap, intmax_t), 8, t);
			ft_allinone(ft, t, str);
		}
		else
		{
			str = ft_width(va_arg(ap, unsigned int), 8, t);
			ft_allinone(ft, t, str);
		}
	}
}

void	ft_end3(va_list ap, t_struct *t, const char *ft, t_conv *p)
{
	char *str;

	if (p->ch == 0 && p->cl == 0)
	{
		if (p->z == 1)
		{
			str = ft_width(va_arg(ap, size_t), 10, t);
			ft_allinone(ft, t, str);
		}
		else if (p->j == 1)
		{
			str = ft_width(va_arg(ap, intmax_t), 10, t);
			ft_allinone(ft, t, str);
		}
		else
		{
			str = ft_width(va_arg(ap, unsigned int), 10, t);
			ft_allinone(ft, t, str);
		}
	}
}
