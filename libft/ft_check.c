/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 15:21:29 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/20 13:34:10 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_exception(t_struct *t, char *str)
{
	char	*nul;

	if (t->point == 1 && t->diese == 1 && t->i == 0 && (t->spe == 'o' ||
			t->spe == 'O'))
	{
		nul = ft_strnew(2);
		nul[0] = '0';
		return (nul);
	}
	return (ft_strdup(str));
}

char		*ft_check(t_struct *t, char *str)
{
	char *cst;
	char *cst1;
	char *cst2;

	cst = "0X";
	cst1 = "0x";
	cst2 = "0";
	if ((t->spe == 'o' || t->spe == 'O') && t->diese == 1 && t->i != 0)
		return (ft_strjoin(cst2, str));
	if (t->spe == 'x' && t->diese == 1 && t->i != 0)
		return (ft_strjoin(cst1, str));
	if (t->spe == 'X' && t->diese == 1 & t->i != 0)
		return (ft_strjoin(cst, str));
	return (ft_exception(t, str));
}

char		*ft_checkid(t_struct *t, char *str)
{
	char *cst;
	char *cst2;
	char *cst3;

	cst = "+";
	cst2 = "-";
	cst3 = " ";
	if (t->pos == 1 && t->nneg != 1)
		return (ft_strjoin(cst, str));
	if (t->space == 1 && t->pos != 1 && t->nneg != 1)
		return (ft_strjoin(cst3, str));
	if (t->nneg == 1)
		return (ft_strjoin(cst2, str));
	return (ft_strdup(str));
}

void		ft_checknb(char const *ft, t_struct *t)
{
	int		j;
	int		len;
	int		s;
	char	*str;

	j = t->per + 1;
	s = 0;
	t->nbl = 0;
	t->point = 0;
	while (ft_strchr("# 0+-", ft[j]) && ft[j])
		j++;
	len = j;
	while (ft[j] != t->spe && ft[j])
	{
		if (ft[j] == '.')
		{
			t->point = 1;
			break ;
		}
		j++;
		s++;
	}
	str = ft_strsub(ft, len, s);
	t->nbl = ft_atoi(str);
	ft_strdel(&str);
}
