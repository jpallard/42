/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 14:41:09 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/24 16:16:25 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_lstadq(t_lst *alst, t_lst *new)
{
	t_lst *tmp;

	tmp = alst;
	while (tmp)
	{
		if (ft_strcmp(tmp->content, new->content) == 0 || (tmp->x == new->x
					&& tmp->y == new->y))
			error();
		tmp = tmp->next;
	}
	tmp = alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

static void		reverted(char *tube, t_lst *alst, t_ant *f)
{
	char	**split;
	char	*join;
	char	*join2;
	int		i;
	t_lst	*tmp;

	i = 0;
	split = ft_strsplit(tube, '-');
	join = ft_strjoin(split[1], "-");
	join2 = ft_strjoin(join, split[0]);
	tmp = alst;
	while (tmp)
	{
		if (ft_strcmp(tmp->content, join2) == 0)
			f->error = 1;
		tmp = tmp->next;
	}
	ft_strdel(&join);
	ft_strdel(&join2);
	while (i < 2)
	{
		ft_strdel(&split[i]);
		i++;
	}
	free(split);
}

void			ft_lstadtube(t_lst *alst, t_lst *new, t_ant *f)
{
	t_lst	*tmp;
	char	*fodder;

	tmp = alst;
	while (tmp)
	{
		if (ft_strcmp(tmp->content, new->content) == 0)
			f->error = 1;
		tmp = tmp->next;
	}
	fodder = ft_strdup(new->content);
	reverted(fodder, alst, f);
	ft_strdel(&fodder);
	if (f->error == 1)
		return ;
	tmp = alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void			ft_lstadfourm(t_tab *lst, t_tab *new)
{
	t_tab *tmp;

	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void			ft_lstadv(t_lst *alst, t_lst *new)
{
	t_lst *tmp;

	tmp = alst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
