/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allinone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 13:23:17 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/18 12:26:51 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_parttwo(const char *ft, t_struct *t, char *str)
{
	char	*tmp;
	char	*tmp2;

	if (t->point == 1)
	{
		tmp = ft_precision(ft, t, str);
		tmp2 = ft_check(t, tmp);
		t->c = t->c + ft_strlen(tmp2);
		ft_putstr(tmp2);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
		ft_strdel(&t->str);
		return ;
	}
	tmp = ft_check(t, str);
	ft_putstr(tmp);
	t->c = t->c + ft_strlen(tmp);
	ft_strdel(&tmp);
	ft_strdel(&t->str);
}

void			ft_allinone(const char *ft, t_struct *t, char *str)
{
	char	*tmp;
	char	*tmp2;

	if (t->nbl > 0)
	{
		if (t->point == 1)
		{
			tmp = ft_precision(ft, t, str);
			tmp2 = ft_space(tmp, t);
			t->c = t->c + ft_strlen(tmp2);
			ft_putstr(tmp2);
			ft_strdel(&tmp);
			ft_strdel(&tmp2);
			ft_strdel(&t->str);
			return ;
		}
		tmp = ft_space(str, t);
		t->c = t->c + ft_strlen(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
		ft_strdel(&t->str);
	}
	else
		ft_parttwo(ft, t, str);
}

static void		ft_parttwoid(const char *ft, t_struct *t, char *str)
{
	char	*tmp;
	char	*tmp2;

	if (t->point == 1)
	{
		tmp = ft_precision(ft, t, str);
		tmp2 = ft_checkid(t, tmp);
		t->c = t->c + ft_strlen(tmp2);
		ft_putstr(tmp2);
		ft_strdel(&tmp);
		ft_strdel(&tmp2);
		ft_strdel(&t->str);
		return ;
	}
	tmp = ft_checkid(t, str);
	ft_putstr(tmp);
	t->c = t->c + ft_strlen(tmp);
	ft_strdel(&tmp);
	ft_strdel(&t->str);
}

void			ft_allinoneid(const char *ft, t_struct *t, char *str)
{
	char	*tmp;
	char	*tmp2;

	if (t->nbl > 0)
	{
		if (t->point == 1)
		{
			tmp = ft_precision(ft, t, str);
			tmp2 = ft_spacealt(tmp, t);
			t->c = t->c + ft_strlen(tmp2);
			ft_putstr(tmp2);
			ft_strdel(&tmp);
			ft_strdel(&tmp2);
			ft_strdel(&t->str);
			return ;
		}
		tmp = ft_spacealt(str, t);
		t->c = t->c + ft_strlen(tmp);
		ft_putstr(tmp);
		ft_strdel(&tmp);
		ft_strdel(&t->str);
	}
	else
		ft_parttwoid(ft, t, str);
}
