/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:40:52 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/24 14:31:43 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		listoupdate(t_tab **tab, int i, t_tab **new)
{
	t_tab	*tmp;

	tmp = tab[i];
	if (!*new)
	{
		*new = ft_lstfourm(tmp->voisin);
		tmp = tmp->next;
	}
	while (tmp)
	{
		ft_lstadfourm(*new, ft_lstfourm(tmp->voisin));
		tmp = tmp->next;
	}
}

static t_tab	*ft_findweight(t_tab **tab, t_ant *f)
{
	t_tab	*new;
	int		i;

	i = 0;
	new = NULL;
	while (i < f->fml)
	{
		if (tab[i]->voisin)
		{
			if (tab[i]->poid == f->poid - 1)
				listoupdate(tab, i, &new);
		}
		i++;
	}
	return (new);
}

static void		ft_giveweight(t_tab **tab, t_tab *road, t_ant *f)
{
	t_tab	*tmp;
	int		i;

	tmp = road;
	while (tmp)
	{
		i = 0;
		while (ft_strcmp(tab[i]->room, tmp->voisin) != 0)
			i++;
		if (tab[i]->poid == 0 && tab[i]->end != 1)
			tab[i]->poid = f->poid;
		tmp = tmp->next;
	}
	f->poid++;
	ft_delltab(road);
	road = NULL;
}

static void		beginsearch(t_tab **tab, int i, t_ant *f, t_tab **road)
{
	t_tab	*tmp;

	ft_checkinone(tab, f, i);
	*road = ft_lstfourm(tab[i]->voisin);
	tmp = tab[i]->next;
	while (tmp)
	{
		ft_lstadfourm(*road, ft_lstfourm(tmp->voisin));
		tmp = tmp->next;
	}
	ft_giveweight(tab, *road, f);
}

int				ft_bfs(t_tab **tab, t_ant *f)
{
	int		i;
	t_tab	*road;

	i = 0;
	road = NULL;
	while (tab[i]->end != 1)
		i++;
	if (tab[i]->voisin)
		beginsearch(tab, i, f, &road);
	else
	{
		if (f->end == -1)
			error();
		return (0);
	}
	while (tab[0]->poid == 0)
	{
		road = ft_findweight(tab, f);
		if (!road)
			return (0);
		ft_giveweight(tab, road, f);
	}
	f->end = 1;
	return (1);
}
