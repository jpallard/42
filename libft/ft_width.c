/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:45:57 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/16 17:15:10 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_width(unsigned long int n, int base, t_struct *t)
{
	const char		*str;
	static int		i = 0;

	t->i = 1;
	if (n == 0)
		t->i = 0;
	i = 0;
	if (!t->str)
		t->str = ft_strnew(33);
	if (base == 10)
	{
		if (t->spe == 'u' || t->spe == 'U')
			return (ft_putcbrx(n, t));
		t->nneg = 0;
		return (ft_putcbr(n, t, t->pos));
	}
	else
	{
		str = "0123456789abcdef";
		if (n >= (unsigned long int)base)
			ft_width(n / base, base, t);
		t->str[i++] = str[n % base];
		t->str[i] = '\0';
	}
	return (t->str);
}
