/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:21:26 by jpallard          #+#    #+#             */
/*   Updated: 2016/11/23 14:13:05 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int			ft_countnum(int n, int count)
{
	unsigned int	tmp;

	count = 0;
	tmp = (unsigned int)n;
	while (tmp > 0)
	{
		tmp /= 10;
		count++;
	}
	return (count);
}

static char			*ft_iszero(int n)
{
	char	*str;

	if (n == 0)
	{
		str = ft_strnew(1);
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		return (str);
	}
	return (0);
}

static void			ft_isnegative(int *n, int *negative, int *i)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
		*i += 1;
	}
}

char				*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				negative;
	unsigned int	tmp;

	i = 0;
	negative = 0;
	ft_isnegative(&n, &negative, &i);
	if (n == 0)
		return (ft_iszero(n));
	i = ft_countnum(n, i) + i;
	str = ft_strnew(i);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	i = i - 1;
	tmp = (unsigned int)n;
	while (tmp)
	{
		str[i--] = tmp % 10 + 48;
		tmp /= 10;
	}
	if (negative == 1)
		str[0] = '-';
	return (str);
}
