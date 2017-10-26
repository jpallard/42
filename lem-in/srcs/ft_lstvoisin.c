/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstvoisin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 13:20:23 by jpallard          #+#    #+#             */
/*   Updated: 2017/09/24 14:34:35 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_copyvslst(char **split, t_tab *fml)
{
	int		i;

	i = 0;
	while (i < 2)
	{
		if (ft_strcmp(split[i], fml->room))
		{
			ft_lstadfourm(fml, ft_lstfourm(split[i]));
			return ;
		}
		i++;
	}
}

void			ft_copyvs(char **split, t_tab *fml)
{
	int		i;

	i = 0;
	while (i < 2)
	{
		if (ft_strcmp(split[i], fml->room))
		{
			if (!(fml->voisin = ft_strdup(split[i])))
				error();
			return ;
		}
		i++;
	}
}

static void		freesplit(char **split, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		ft_strdel(&split[j]);
		j++;
	}
	free(split);
	split = NULL;
}

t_lst			*ft_lstvoisin(t_tab *fml, t_lst *tmp2)
{
	int		k;
	int		i;
	char	**split;

	k = 0;
	i = 0;
	while (tmp2)
	{
		if (ft_strstr(tmp2->content, fml->room))
		{
			if (!(split = ft_strsplit(tmp2->content, '-')))
				error();
			while (i < 2)
				ft_copyadlst(split, &i, fml, &k);
			freesplit(split, 2);
		}
		i = 0;
		tmp2 = tmp2->next;
		if (k == 1)
			break ;
	}
	return (tmp2);
}

t_lst			*firstvoisin(t_tab *fml, t_lst *tmp2)
{
	int		k;
	int		i;
	char	**split;

	k = 0;
	i = 0;
	while (tmp2)
	{
		if (ft_strstr(tmp2->content, fml->room))
		{
			if (!(split = ft_strsplit(tmp2->content, '-')))
				error();
			while (i < 2)
				ft_copypasta(split, &i, fml, &k);
			freesplit(split, 2);
		}
		i = 0;
		tmp2 = tmp2->next;
		if (k == 1)
			break ;
	}
	return (tmp2);
}
