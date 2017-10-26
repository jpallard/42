/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:19:50 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/25 11:47:53 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	error(void)
{
	ft_putendl_fd("ERROR", 1);
	exit(EXIT_FAILURE);
}

void	ft_checkant(char *str, t_ant *f)
{
	int		i;

	i = 0;
	if (!str[i])
		error();
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error();
		i++;
	}
	f->nbant = ft_longatoi(str);
	if (f->nbant <= 0)
		error();
}

t_lst	*ft_checkt(char *line, t_ant *f, t_lst *room, t_lst *tube)
{
	int		nbword;

	f->tube = 1;
	if (f->start != -1 || f->end != -1)
		error();
	nbword = ft_countnb(line);
	if (*line == '#')
		return (tube);
	else if (nbword == 1)
	{
		equalroom(room, line, f);
		if (f->error == 1)
			return (tube);
		tube = lsttube(tube, line, f);
	}
	else
		f->error = 1;
	return (tube);
}

void	ft_checkother(char *line, t_ant *f)
{
	if (ft_strcmp(line, "##start") == 0)
	{
		if (f->start != 0)
			error();
		f->start++;
		return ;
	}
	else if (ft_strcmp(line, "##end") == 0)
	{
		if (f->end != 0)
			error();
		f->end++;
		return ;
	}
	else if (*line == 'L')
		error();
}

t_lst	*ft_checkroom(char *line, t_ant *f, t_lst *room)
{
	char	**split;
	int		i;

	if (*line == '#' || *line == 'L')
		ft_checkother(line, f);
	else if (ft_countnb(line) == 3)
	{
		i = 0;
		if (!(split = ft_strsplit(line, ' ')))
			exit(EXIT_FAILURE);
		if (!room)
			room = initroom(split[0], split, f);
		else
			ft_lstadq(room, initroom(split[0], split, f));
		while (i < 3)
		{
			ft_strdel(&split[i]);
			i++;
		}
		free(split);
	}
	return (room);
}
