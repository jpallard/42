/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precisions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:05:43 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/18 12:32:31 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_redux(char *str, t_struct *t)
{
	int		j;
	int		k;
	char	*tmp;

	j = t->nbp;
	k = ft_strlen(str);
	tmp = ft_strdup(str);
	if (k > j)
	{
		tmp[j] = '\0';
		return (tmp);
	}
	else
		return (str);
}

char			*ft_precisions(const char *ft, t_struct *t, char *str)
{
	int		i;
	int		j;
	int		len;
	char	*nb;

	j = 0;
	t->nbp = 0;
	i = t->per;
	while (ft[i] != '.' && ft[i])
		i++;
	len = i + 1;
	while (ft[i] != t->spe && ft[i])
	{
		j++;
		i++;
	}
	nb = ft_strsub(ft, len, j);
	t->nbp = ft_atoi(nb);
	return (ft_redux(str, t));
}
