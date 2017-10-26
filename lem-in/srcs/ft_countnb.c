/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:39:38 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/02 11:28:16 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_countnb(char *str)
{
	int		i;
	int		number;

	i = 0;
	number = 0;
	while (*str)
	{
		if (number == 1 && *str == ' ')
			number = 0;
		if (number == 0 && *str != ' ')
		{
			number = 1;
			i++;
		}
		str++;
	}
	return (i);
}
