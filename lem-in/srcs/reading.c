/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 15:42:56 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/24 15:48:36 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lst	*reading(t_lst **tube, t_lst **room, t_ant *f, char *line)
{
	int		i;
	t_lst	*fml;

	i = 0;
	fml = NULL;
	while (get_next_line(0, &line) == 1)
	{
		fml = fourmiliere(line, fml);
		if (i++ == 0)
			ft_checkant(line, f);
		else if ((ft_countnb(line) == 3 || *line == '#' || *line == 'L') &&
				f->tube != 1)
			*room = ft_checkroom(line, f, *room);
		else if (ft_countnb(line) == 1 || *line == '#')
			*tube = ft_checkt(line, f, *room, *tube);
		else
			f->error = 1;
		ft_strdel(&line);
		if (f->error == 1)
			break ;
	}
	return (fml);
}
