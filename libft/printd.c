/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:20:54 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/16 16:34:32 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printd2(va_list ap, t_struct *t, const char *ft, t_conv *p)
{
	char *str;

	if (p->cl == 0 && p->ch == 0)
	{
		if (p->z == 1)
		{
			str = ft_width(va_arg(ap, size_t), 10, t);
			ft_allinoneid(ft, t, str);
		}
		else if (p->j == 1)
		{
			str = ft_width(va_arg(ap, intmax_t), 10, t);
			ft_allinoneid(ft, t, str);
		}
		else
		{
			str = ft_width(va_arg(ap, int), 10, t);
			ft_allinoneid(ft, t, str);
		}
	}
}

void	printd(va_list ap, t_struct *t, const char *ft, t_conv *p)
{
	char *str;

	if (p->cl == 1)
	{
		str = ft_width(va_arg(ap, long long int), 10, t);
		ft_allinoneid(ft, t, str);
	}
	else if (p->ch == 1)
	{
		str = ft_width((short int)va_arg(ap, int), 10, t);
		ft_allinoneid(ft, t, str);
	}
	else if (p->ch == 2)
	{
		str = ft_width((char)va_arg(ap, int), 10, t);
		ft_allinoneid(ft, t, str);
	}
	ft_printd2(ap, t, ft, p);
}
