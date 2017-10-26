/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 15:07:34 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/24 15:52:50 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				nbvs(t_lst *tube, t_lst *room)
{
	t_lst	*tmp;
	t_lst	*tmp2;
	int		i;

	i = 0;
	tmp = tube;
	tmp2 = room;
	while (tmp2->start != 1 && tmp2)
		tmp2 = tmp2->next;
	while (tmp)
	{
		if (ft_strstr(tmp->content, tmp2->content))
			i++;
		tmp = tmp->next;
	}
	return (i);
}

static t_lst	*finish(t_tab *fml, t_lst *room, t_lst *tube, t_tab **tab)
{
	t_lst	*tmp;
	t_lst	*tmp2;
	int		i;
	int		j;

	tmp2 = tube;
	tmp = room;
	j = 0;
	skiproom(&tmp, tab);
	if (tmp->end == 1)
		fml->end = 1;
	if (!(fml->room = ft_strdup(tmp->content)))
		error();
	tmp = room;
	i = ft_searchngb(tube, fml->room);
	if (i > 0)
		tmp2 = firstvoisin(fml, tmp2);
	j++;
	while (j < i)
	{
		tmp2 = ft_lstvoisin(fml, tmp2);
		j++;
	}
	return (room);
}

static t_lst	*initf(t_tab *fml, t_lst *room, t_lst *tube)
{
	t_lst	*tmp;
	t_lst	*tmp2;
	int		i;
	int		j;

	tmp2 = tube;
	tmp = room;
	j = 0;
	i = nbvs(tube, room);
	while (tmp->start != 1)
		tmp = tmp->next;
	if (!(fml->room = ft_strdup(tmp->content)))
		error();
	tmp = room;
	if (i > 0)
		tmp2 = firstvoisin(fml, tmp2);
	j++;
	while (j < i)
	{
		tmp = room;
		tmp2 = ft_lstvoisin(fml, tmp2);
		j++;
	}
	return (room);
}

static t_tab	**ft_stock(t_lst *room, t_lst *tube)
{
	t_tab	**fml;
	int		i;
	int		j;

	j = 0;
	if (!(fml = (t_tab**)malloc(sizeof(t_tab) * ft_lstlon(room))))
		error();
	i = nbvs(tube, room);
	fml[j] = initstock(fml[j]);
	room = initf(fml[j], room, tube);
	j++;
	while (j < ft_lstlon(room))
	{
		fml[j] = initstock(fml[j]);
		room = finish(fml[j], room, tube, fml);
		j++;
	}
	return (fml);
}

t_tab			**parsing(t_lst *room, t_ant *f)
{
	t_lst	*tube;
	t_tab	**tab;
	t_lst	*fml;
	char	*line;

	tube = NULL;
	fml = NULL;
	line = NULL;
	fml = reading(&tube, &room, f, line);
	if (!tube)
		error();
	f->fml = ft_lstlon(room);
	tab = ft_stock(room, tube);
	ft_tabcheck(tab, f);
	ft_dellst(&fml);
	ft_dellstar(&tube);
	ft_dellstar(&room);
	return (tab);
}
