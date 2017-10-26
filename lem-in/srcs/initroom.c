/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initroom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 11:04:58 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/20 15:24:01 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		checkint(char **split)
{
	int		i;

	i = 0;
	while (split[1][i])
	{
		if (!(ft_isdigit(split[1][i])))
			error();
		i++;
	}
	i = 0;
	while (split[2][i])
	{
		if (!(ft_isdigit(split[2][i])))
			error();
		i++;
	}
}

t_lst		*initroom(char *line, char **split, t_ant *f)
{
	t_lst *new;

	if (!(new = ft_lstant(line)))
		error();
	if (f->end == 1)
	{
		new->end = 1;
		f->end = -1;
	}
	if (f->start == 1)
	{
		new->start = 1;
		f->start = -1;
	}
	checkint(split);
	if (ft_strstr(line, "-"))
		error();
	if (new->start == 1 && new->end == 1)
		error();
	new->x = ft_longatoi(split[1]);
	new->y = ft_longatoi(split[2]);
	return (new);
}

t_ant		*ft_initstruct(t_ant *f)
{
	if (!(f = (t_ant *)ft_memalloc(sizeof(t_ant))))
		error();
	f->nbant = 0;
	f->start = 0;
	f->end = 0;
	f->error = 0;
	f->first = 0;
	f->tube = 0;
	f->fml = 0;
	f->poid = 1;
	return (f);
}

void		ft_lastinit(t_lol *lst)
{
	t_lst	*tmp;

	while (lst)
	{
		tmp = lst->lst;
		while (tmp)
		{
			tmp->x = 0;
			tmp->y = 0;
			tmp = tmp->next;
		}
		lst = lst->suivant;
	}
}
