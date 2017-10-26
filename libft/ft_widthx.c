/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widthx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:48:50 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/14 16:58:12 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_widthx(unsigned long int n, int base, t_struct *t)
{
	const char		*str;
	static int		i;

	t->i = 1;
	if (n == 0)
		t->i = 0;
	i = 0;
	if (!t->str)
		t->str = ft_strnew(33);
	if (base == 10)
		ft_putcbr(n, t, t->pos);
	else
	{
		str = "0123456789ABCDEF";
		if (n >= (unsigned long int)base)
			ft_widthx(n / base, base, t);
		t->str[i] = str[n % base];
		i++;
		t->str[i] = '\0';
	}
	return (t->str);
}
