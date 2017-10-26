/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsttube.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 14:36:56 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/24 14:42:21 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lst			*lsttube(t_lst *tube, char *line, t_ant *f)
{
	if (!tube)
	{
		tube = ft_lstant(line);
		if (!tube)
			exit(EXIT_FAILURE);
	}
	else
		ft_lstadtube(tube, ft_lstant(line), f);
	return (tube);
}

static void		searchroom(t_lst *room, t_lst *tmp, int *i, char **split)
{
	tmp = room;
	while (tmp)
	{
		if (*i < 2)
		{
			if (ft_strcmp(split[*i], tmp->content) == 0)
			{
				*i = *i + 1;
				tmp = room;
			}
			else
				tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
}

static int		morethanone(char *line, t_ant *f)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == '-')
			j++;
		i++;
	}
	if (j > 1)
	{
		f->error = 1;
		return (1);
	}
	return (0);
}

void			equalroom(t_lst *room, char *line, t_ant *f)
{
	int		i;
	char	**split;
	t_lst	*tmp;

	i = 0;
	tmp = room;
	if (!ft_strchr(line, '-'))
	{
		f->error = 1;
		return ;
	}
	if (morethanone(line, f))
		return ;
	split = ft_strsplit(line, '-');
	searchroom(room, tmp, &i, split);
	if (i != 2)
		f->error = 1;
	i = 0;
	while (i < 2)
	{
		ft_strdel(&split[i]);
		i++;
	}
	free(split);
}
