/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dellst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 15:41:03 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/21 18:57:13 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_searchngb(t_lst *tube, char *room)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	tmp = tube;
	while (tmp)
	{
		if (ft_strstr(tmp->content, room))
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_dellst(t_lst **fml)
{
	t_lst	*previous;
	t_lst	*tmp;

	previous = *fml;
	while (previous)
	{
		tmp = previous->next;
		ft_putendl(previous->content);
		free(previous->content);
		free(previous);
		previous = tmp;
	}
	ft_putstr("\n");
	*fml = NULL;
}

void	ft_dellstar(t_lst **fml)
{
	t_lst	*previous;
	t_lst	*tmp;

	previous = *fml;
	while (previous)
	{
		tmp = previous->next;
		free(previous->content);
		free(previous);
		previous = tmp;
	}
	*fml = NULL;
}

void	freelol(t_lol *lst)
{
	t_lol	*previous;
	t_lol	*tmp;

	previous = lst;
	while (previous)
	{
		tmp = previous->suivant;
		ft_dellstar(&previous->lst);
		free(previous);
		previous = tmp;
	}
	lst = NULL;
}

void	ft_delltab(t_tab *tab)
{
	t_tab	*previous;
	t_tab	*tmp;

	previous = tab;
	while (previous)
	{
		tmp = previous->next;
		if (previous->room)
			free(previous->room);
		if (previous->voisin)
			free(previous->voisin);
		free(previous);
		previous = tmp;
	}
	previous = NULL;
}
