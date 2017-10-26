/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:01:37 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/19 14:09:17 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_lstlon(t_lst *list)
{
	t_lst	*tmp;
	int		i;

	tmp = list;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int		ft_lstlol(t_lol *lst)
{
	t_lol	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		if (tmp->lst)
			i++;
		tmp = tmp->suivant;
	}
	return (i);
}
