/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:14:18 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/16 16:52:00 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putcbr(long long int n, t_struct *t, int pos)
{
	static int			i = 0;

	i = 0;
	if (n == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	if (n < 0)
	{
		if (pos == 1)
			pos = 0;
		n *= -1;
		t->nneg = 1;
	}
	if (n > 9)
		ft_putcbr(n / 10, t, pos);
	t->str[i] = n % 10 + 48;
	i++;
	t->str[i] = '\0';
	return (t->str);
}
