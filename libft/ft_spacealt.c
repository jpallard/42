/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spacealt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:37:49 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/20 13:34:57 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_sign(t_struct *t)
{
	if (t->space == 1 || t->pos == 1 || t->nneg == 1)
		return (1);
	else
		return (0);
}

static char		*ft_elsealt(t_struct *t, char *str, char *nb)
{
	char	*tmp;
	char	*tmp2;

	if (t->point == 1)
	{
		tmp = ft_checkid(t, str);
		tmp2 = ft_strjoin(nb, tmp);
		ft_strdel(&nb);
		ft_strdel(&tmp);
		return (tmp2);
	}
	if (t->zero == 1)
	{
		tmp = ft_strjoin(nb, str);
		tmp2 = ft_checkid(t, tmp);
		ft_strdel(&nb);
		ft_strdel(&tmp);
		return (tmp2);
	}
	tmp = ft_checkid(t, str);
	tmp2 = ft_strjoin(nb, tmp);
	ft_strdel(&nb);
	ft_strdel(&tmp);
	return (tmp2);
}

static char		*ft_negalt(t_struct *t, char *str, char *nb)
{
	char *tmp;
	char *tmp2;

	tmp = ft_checkid(t, str);
	tmp2 = ft_strjoin(tmp, nb);
	ft_strdel(&nb);
	ft_strdel(&tmp);
	return (tmp2);
}

char			*ft_spacealt(char *str, t_struct *t)
{
	char	*nb;
	char	c;
	int		i;
	int		j;

	j = (t->nbl - ft_strlen(str) - ft_sign(t));
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
			return (ft_negalt(t, str, nb));
		else
			return (ft_elsealt(t, str, nb));
	}
	return (ft_checkid(t, str));
}
