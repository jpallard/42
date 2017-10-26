/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 15:47:41 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/24 16:20:05 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int argc, char **argv)
{
	t_lst	*room;
	t_lol	*lst;
	t_ant	*f;
	t_tab	**tab;

	room = NULL;
	lst = NULL;
	tab = NULL;
	f = NULL;
	if (argc != 1)
		error();
	f = ft_initstruct(f);
	tab = parsing(room, f);
	while (ft_bfs(tab, f) == 1)
	{
		lst = ft_travel(tab, lst);
		ft_multipath(tab, lst, f);
		f->poid = 1;
	}
	ft_addend(lst, tab, f);
	freeforall(tab, f);
	argv[0] = NULL;
	return (0);
}
