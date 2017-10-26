/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multipath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:17:30 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/24 14:15:19 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_copyadlst(char **split, int *i, t_tab *fml, int *k)
{
	if (ft_strcmp(split[*i], fml->room) == 0)
	{
		ft_copyvslst(split, fml);
		*k = 1;
	}
	*i = *i + 1;
}

void	ft_copypasta(char **split, int *i, t_tab *fml, int *k)
{
	if (ft_strcmp(split[*i], fml->room) == 0)
	{
		ft_copyvs(split, fml);
		*k = 1;
	}
	*i = *i + 1;
}

void	ft_path(t_tab *tmp, t_tab **tab, t_lol *tot, t_num *n)
{
	while (n->poid > 1)
	{
		if (tab[n->i]->poid == n->poid - 1 && tab[n->i]->voisin)
		{
			tmp = tab[n->i];
			while (tmp)
			{
				if (ft_strcmp(n->room, tmp->voisin) == 0)
				{
					if (!tot->lst)
						tot->lst = ft_lstant(tab[n->i]->room);
					else
						ft_lstadv(tot->lst, ft_lstant(tab[n->i]->room));
					ft_strdel(&n->room);
					if (!(n->room = ft_strdup(tab[n->i]->room)))
						error();
					n->poid--;
					n->i = 0;
					break ;
				}
				tmp = tmp->next;
			}
		}
		n->i++;
	}
}

void	ft_multipath(t_tab **tab, t_lol *lst, t_ant *f)
{
	t_lst	*tmp;
	t_lol	*tmp2;
	int		i;

	tmp2 = lst;
	while (tmp2->suivant != NULL)
		tmp2 = tmp2->suivant;
	i = 0;
	tmp = tmp2->lst;
	while (i < f->fml)
	{
		while (tmp)
		{
			if (tab[i]->voisin)
				tab[i] = ft_delngb(tab[i], tmp);
			tmp = tmp->next;
		}
		tmp = tmp2->lst;
		tab[i]->poid = 0;
		i++;
	}
}
