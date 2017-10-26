/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatidoforan.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 16:25:04 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/24 16:35:07 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		whatidoforan(t_lol *lst)
{
	t_lol	*tmp;
	t_lst	*tmp2;

	tmp = lst;
	while (tmp)
	{
		if (tmp->lst)
		{
			tmp2 = tmp->lst;
			while (tmp2)
			{
				if (tmp2->x != 0)
					return (1);
				tmp2 = tmp2->next;
			}
		}
		tmp = tmp->suivant;
	}
	return (0);
}
