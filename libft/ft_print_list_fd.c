/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 10:54:38 by jpallard          #+#    #+#             */
/*   Updated: 2016/11/25 13:56:34 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		print_list_fd(t_list *list, int fd)
{
	while (list)
	{
		ft_putendl_fd(list->content, fd);
		list = list->next;
	}
}
