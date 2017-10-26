/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:39:27 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/18 17:16:44 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_spec(const char *ft, va_list ap, t_struct *t, t_conv *p)
{
	char	*str;

	if (t->spe == 's')
	{
		ft_length(ft, t, p, t->per);
		if (p->cl == 1)
		{
			ft_pus(ap, t, p, ft);
			return ;
		}
		else
		{
			str = va_arg(ap, char *);
			if (str == NULL)
			{
				ft_putstr("(null)");
				t->c = t->c + 6;
				return ;
			}
			ft_flag(ft, t, t->per);
			ft_checknb(ft, t);
			ft_prints(str, ft, t);
		}
	}
}

void	ft_sped(const char *ft, va_list ap, t_struct *t, t_conv *p)
{
	int		s;

	if (t->spe == 'i' || t->spe == 'd' || t->spe == 'D')
	{
		ft_length(ft, t, p, t->per);
		ft_flag(ft, t, t->per);
		ft_checknb(ft, t);
		printd(ap, t, ft, p);
	}
	else
	{
		ft_flag(ft, t, t->per);
		ft_checknb(ft, t);
		ft_length(ft, t, p, t->per);
		if (p->cl == 1)
		{
			p->exe = 0;
			ft_puni(ap, t, p, ft);
		}
		else
		{
			s = va_arg(ap, int);
			ft_printc(s, t);
		}
	}
}
