/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fourmiliere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 11:42:36 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/16 13:41:51 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lst		*fourmiliere(char *line, t_lst *fml)
{
	if (!fml)
	{
		fml = ft_lstant(line);
		if (!fml)
			error();
	}
	else
		ft_lstadv(fml, ft_lstant(line));
	return (fml);
}
