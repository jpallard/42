/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 17:15:21 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/21 15:13:58 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lst	*ft_lstant(char *content)
{
	t_lst		*lst;

	if (!(lst = (t_lst*)malloc(sizeof(t_lst))))
		error();
	lst->content = NULL;
	lst->next = NULL;
	if (content == NULL)
		lst->content = NULL;
	else
	{
		if (!(lst->content = ft_strdup(content)))
			error();
	}
	return (lst);
}

t_tab	*ft_lstfourm(char *content)
{
	t_tab		*lst;

	if (!(lst = (t_tab*)malloc(sizeof(t_tab))))
		error();
	lst->room = NULL;
	if (content == NULL)
		lst->voisin = NULL;
	else
	{
		if (!(lst->voisin = ft_strdup(content)))
			error();
	}
	lst->next = NULL;
	return (lst);
}
