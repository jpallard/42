/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endofpars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 17:34:13 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/23 18:16:39 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_tab	*initstock(t_tab *fml)
{
	if (!(fml = (t_tab*)malloc(sizeof(t_tab))))
		error();
	fml->voisin = NULL;
	fml->next = NULL;
	fml->room = NULL;
	fml->end = 0;
	fml->poid = 0;
	return (fml);
}

void	skiproom(t_lst **tmp, t_tab **tab)
{
	int		j;

	j = 0;
	while (tab[j]->room)
	{
		while (ft_strcmp(tab[j]->room, (*tmp)->content) == 0)
		{
			(*tmp) = (*tmp)->next;
			j = 0;
		}
		j++;
	}
}
