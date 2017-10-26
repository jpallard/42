/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 12:33:10 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/24 16:13:26 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_checkngb(t_tab *tmp, t_tab **tab, t_ant *f)
{
	int		i;
	t_tab	*ngb;

	ngb = tmp;
	while (ngb)
	{
		i = 1;
		if (ngb->voisin)
			while (i < f->fml)
			{
				if (ft_strcmp(ngb->voisin, tab[i]->room) == 0)
				{
					if (tab[i]->poid == 0)
						tab[i]->poid = 1;
				}
				i++;
			}
		ngb = ngb->next;
	}
}

static void		findiftrue(t_tab **tab, t_ant *f)
{
	int		i;

	i = 1;
	while (i < f->fml)
	{
		if (tab[i]->poid == 1)
		{
			tab[i]->poid = -1;
			ft_checkngb(tab[i], tab, f);
			i = 0;
		}
		i++;
	}
	i = 0;
	while (tab[i]->end != 1)
		i++;
	if (tab[i]->poid != -1)
		error();
}

static void		resettab(t_tab **tab, t_ant *f)
{
	int		i;

	i = 0;
	while (i < f->fml)
	{
		tab[i]->poid = 0;
		i++;
	}
}

void			ft_tabcheck(t_tab **tab, t_ant *f)
{
	t_tab	*tmp;
	int		i;

	i = 1;
	tmp = tab[0];
	if (!tab[0]->voisin)
		error();
	else
	{
		while (i < f->fml && tmp)
		{
			if (tab[i]->voisin)
				if (ft_strcmp(tmp->voisin, tab[i]->room) == 0)
				{
					tab[i]->poid = 1;
					tmp = tmp->next;
					i = 0;
				}
			i++;
		}
	}
	findiftrue(tab, f);
	resettab(tab, f);
}
