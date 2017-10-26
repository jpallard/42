/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 13:42:29 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/24 14:30:39 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_start(t_lol *lst, t_ant *f)
{
	t_lol	*tmp;
	t_lst	*tmp2;
	int		i;

	i = 1;
	tmp = lst;
	while (f->nbant > 0)
	{
		while (tmp)
		{
			tmp2 = tmp->lst;
			ft_printf("L%d-%s ", i, tmp2->content);
			f->nbant--;
			tmp2->x = i;
			i++;
			tmp = tmp->suivant;
			if (f->nbant == 0)
				goalatstart(lst);
		}
		ft_putendl("");
		break ;
	}
	return (i);
}

static int		ft_move(t_lst *lst, t_ant *f, int i)
{
	t_lst		*tmp;
	int			j;
	int			k;

	tmp = lst;
	j = tmp->x;
	tmp->x = i;
	i++;
	f->nbant--;
	if (f->nbant >= 0)
		while (tmp)
		{
			if (tmp->x != 0)
				ft_printf("L%d-%s ", tmp->x, tmp->content);
			if (tmp->next)
				k = tmp->next->x;
			tmp = tmp->next;
			if (tmp)
				tmp->x = j;
			j = k;
		}
	return (i);
}

static void		finishthefight(t_lst *lst)
{
	int		j;
	int		k;
	t_lst	*tmp;

	tmp = lst;
	j = tmp->x;
	tmp->x = 0;
	while (tmp)
	{
		if (tmp->x != 0)
			ft_printf("L%d-%s ", tmp->x, tmp->content);
		if (tmp->next)
			k = tmp->next->x;
		tmp = tmp->next;
		if (tmp)
			tmp->x = j;
		j = k;
	}
}

static void		ft_totheend(t_lol *lst, t_ant *f)
{
	t_lol	*tmp;
	int		i;

	tmp = lst;
	ft_lastinit(tmp);
	i = ft_start(lst, f);
	while (f->nbant > 0)
	{
		while (tmp)
		{
			if (f->nbant > 0)
			{
				i = ft_move(tmp->lst, f, i);
				tmp = tmp->suivant;
			}
			else
			{
				finishthefight(tmp->lst);
				tmp = tmp->suivant;
			}
		}
		ft_putendl("");
		tmp = lst;
	}
}

void			ft_addend(t_lol *lst, t_tab **tab, t_ant *f)
{
	t_lol	*tmp;
	t_lst	*tmp2;
	int		i;

	i = 0;
	while (tab[i]->end != 1)
		i++;
	tmp = lst;
	while (tmp)
	{
		tmp2 = tmp->lst;
		ft_lstadv(tmp2, ft_lstant(tab[i]->room));
		tmp = tmp->suivant;
	}
	ft_totheend(lst, f);
	goal(lst);
	freelol(lst);
}
