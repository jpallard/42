/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:14:18 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/16 16:52:23 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putcbrx(unsigned long int n, t_struct *t)
{
	static int			i = 0;

	i = 0;
	if (n > 9)
		ft_putcbrx(n / 10, t);
	t->str[i] = n % 10 + 48;
	i++;
	t->str[i] = '\0';
	return (t->str);
}
