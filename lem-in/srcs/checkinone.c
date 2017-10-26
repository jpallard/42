/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkinone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 15:48:28 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/24 14:28:50 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void	ft_zawarudo(char *end, t_ant *f)
{
	int		i;

	i = 1;
	while (f->nbant > 0)
	{
		ft_printf("L%d-%s ", i, end);
		i++;
		f->nbant--;
	}
	ft_putendl("");
	exit(EXIT_SUCCESS);
}

void			ft_checkinone(t_tab **tab, t_ant *f, int i)
{
	t_tab *tmp;

	tmp = tab[i];
	while (tmp)
	{
		if (ft_strcmp(tab[0]->room, tmp->voisin) == 0)
			ft_zawarudo(tab[i]->room, f);
		tmp = tmp->next;
	}
}
