/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delngb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 12:09:55 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/24 14:32:55 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_tab	*ft_firstdel(t_tab *tab, t_tab *pvs)
{
	if (tab->next != NULL)
	{
		if (tab->end == 1)
			pvs->next->end = 1;
		tab = pvs->next;
		if (!(tab->room = ft_strdup(pvs->room)))
			error();
		ft_strdel(&pvs->room);
		ft_strdel(&pvs->voisin);
		free(pvs);
	}
	else
	{
		free(pvs->voisin);
		pvs->voisin = NULL;
	}
	return (tab);
}

t_tab			*ft_delngb(t_tab *tab, t_lst *lst)
{
	t_tab	*pvs;
	t_tab	*tmp;

	pvs = tab;
	if (ft_strcmp(pvs->voisin, lst->content) == 0)
		return (ft_firstdel(tab, pvs));
	tmp = pvs->next;
	while (tmp)
	{
		if (ft_strcmp(tmp->voisin, lst->content) == 0)
		{
			pvs->next = tmp->next;
			ft_strdel(&tmp->voisin);
			free(tmp);
			return (tab);
		}
		else
		{
			pvs = tmp;
			tmp = tmp->next;
		}
	}
	return (tab);
}
