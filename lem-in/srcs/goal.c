/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 14:13:09 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/24 16:31:28 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			goalatstart(t_lol *lst)
{
	ft_putendl("");
	goal(lst);
	exit(EXIT_SUCCESS);
}

static void		checklist(t_lst **lst)
{
	t_lst *tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->x != 0)
			return ;
		tmp = tmp->next;
	}
	ft_dellstar(lst);
}

static void		updateroad(t_lst *tmp, int *i, int *k)
{
	if (tmp)
	{
		*k = tmp->x;
		tmp->x = *i;
		if (tmp->x != 0)
			ft_printf("L%d-%s ", tmp->x, tmp->content);
		*i = *k;
	}
}

static int		checkmate(t_lst **lst, int j)
{
	t_lst	*tmp;
	int		i;
	int		k;

	tmp = *lst;
	k = 0;
	while (tmp && tmp->x == 0)
		tmp = tmp->next;
	if (tmp)
	{
		i = tmp->x;
		tmp->x = 0;
		while (tmp)
		{
			tmp = tmp->next;
			updateroad(tmp, &i, &k);
		}
		return (j);
	}
	ft_dellstar(lst);
	return (j - 1);
}

void			goal(t_lol *lst)
{
	t_lol	*tmp;
	int		i;

	tmp = lst;
	while (tmp)
	{
		checklist(&tmp->lst);
		tmp = tmp->suivant;
	}
	tmp = lst;
	i = ft_lstlol(lst);
	while (i > 0)
	{
		while (tmp)
		{
			if (tmp->lst)
				i = checkmate(&tmp->lst, i);
			tmp = tmp->suivant;
		}
		if (whatidoforan(lst))
			ft_putendl("");
		tmp = lst;
	}
}
