/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 12:01:59 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/20 12:53:57 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

long long int		ft_longatoi(const char *str)
{
	int				i;
	long long int	nb;
	int				negatif;

	i = 0;
	nb = 0;
	negatif = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		negatif = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb = nb + (str[i] - 48);
		i++;
	}
	if (nb > INT_MAX || nb < INT_MIN)
		error();
	if (negatif == 1)
		return (-nb);
	return (nb);
}
