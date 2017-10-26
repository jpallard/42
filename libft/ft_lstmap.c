/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 12:41:02 by jpallard          #+#    #+#             */
/*   Updated: 2016/11/24 17:10:08 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*second;

	if (!lst)
		return (NULL);
	if (!(second = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	second = f(lst);
	first = second;
	while (lst->next)
	{
		first->next = f(lst->next);
		first = first->next;
		lst = lst->next;
	}
	return (second);
}
