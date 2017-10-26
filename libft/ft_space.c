/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 14:55:11 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/20 13:34:36 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_diese(t_struct *t)
{
	int i;

	i = 0;
	if ((t->spe == 'o' || t->spe == 'O') && t->diese == 1)
		i = 1;
	if ((t->spe == 'x' || t->spe == 'X') && t->diese == 1)
	{
		if (t->point == 1)
			i = 0;
		else
			i = 2;
	}
	return (i);
}

static char		*ft_else(t_struct *t, char *str, char *nb)
{
	char *tmp;
	char *tmp2;

	if (t->point == 1 && t->diese == 1)
	{
		tmp = ft_check(t, str);
		tmp2 = ft_strjoin(nb, tmp);
		ft_strdel(&tmp);
		return (tmp2);
	}
	if (t->zero == 1)
	{
		tmp = ft_strjoin(nb, str);
		tmp2 = ft_check(t, tmp);
		ft_strdel(&tmp);
		return (tmp2);
	}
	tmp = ft_check(t, str);
	tmp2 = ft_strjoin(nb, tmp);
	ft_strdel(&tmp);
	return (tmp2);
}

static char		*ft_neg(t_struct *t, char *str, char *nb)
{
	char *tmp;
	char *tmp2;

	tmp = ft_check(t, str);
	tmp2 = ft_strjoin(tmp, nb);
	ft_strdel(&tmp);
	return (tmp2);
}

char			*ft_space(char *str, t_struct *t)
{
	char	*nb;
	char	c;
	int		i;
	int		j;

	j = (t->nbl - ft_strlen(str) - ft_diese(t));
	if (j > 0)
	{
		c = ' ';
		if (t->zero == 1 && t->neg != 1 && t->point != 1)
			c = '0';
		i = 0;
		nb = ft_strnew(j);
		while (i < j)
		{
			nb[i] = c;
			i++;
		}
		if (t->neg == 1)
			return (ft_neg(t, str, nb));
		else
			return (ft_else(t, str, nb));
	}
	return (ft_check(t, str));
}
