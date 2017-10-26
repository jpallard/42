/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_travel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:26:18 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/24 14:36:30 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_newroad(t_lol *lst, t_tab **tab, t_num *n)
{
	t_lol	*tot;
	t_lol	*tle;
	t_tab	*tmp;

	n->i = 0;
	tot = NULL;
	if (!tot)
	{
		if (!(tot = (t_lol*)malloc(sizeof(t_lol))))
			error();
		tot->lst = NULL;
		tot->suivant = NULL;
	}
	tmp = NULL;
	ft_path(tmp, tab, tot, n);
	ft_strdel(&n->room);
	tle = lst;
	while (tle->suivant != NULL)
		tle = tle->suivant;
	tle->suivant = tot;
}

static t_num	*ft_initlst(t_lol **lst, t_tab *tab, t_num *n)
{
	if (!*lst)
	{
		if (!(*lst = (t_lol*)malloc(sizeof(t_lol))))
			error();
		(*lst)->lst = NULL;
		(*lst)->suivant = NULL;
	}
	if (!n)
	{
		if (!(n = (t_num*)malloc(sizeof(t_num))))
			error();
		n->room = NULL;
		n->poid = 0;
		n->i = 0;
	}
	if (!(n->room = ft_strdup(tab->room)))
		error();
	n->poid = tab->poid;
	return (n);
}

static void		inloop(t_lst **lst, char *place, t_num *n)
{
	if (!*lst)
		*lst = ft_lstant(place);
	else
		ft_lstadv(*lst, ft_lstant(place));
	ft_strdel(&n->room);
	if (!(n->room = ft_strdup(place)))
		error();
	n->poid = n->poid - 1;
}

static void		loop(t_tab *tmp, t_tab **tab, t_num *n, t_lol *lst)
{
	while (tmp)
	{
		if (ft_strcmp(n->room, tmp->voisin) == 0)
		{
			inloop(&lst->lst, tab[n->i]->room, n);
			n->i = 0;
			break ;
		}
		tmp = tmp->next;
	}
}

t_lol			*ft_travel(t_tab **tab, t_lol *lst)
{
	t_tab	*tmp;
	t_num	*n;

	n = NULL;
	n = ft_initlst(&lst, tab[0], n);
	if (!lst->lst)
	{
		while (n->poid > 1)
		{
			if (tab[n->i]->poid == n->poid - 1 && tab[n->i]->voisin)
			{
				tmp = tab[n->i];
				loop(tmp, tab, n, lst);
			}
			n->i++;
		}
		ft_strdel(&n->room);
	}
	else
		ft_newroad(lst, tab, n);
	free(n);
	n = NULL;
	return (lst);
}
