/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:50:32 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/18 12:45:59 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_this_isnt_even_my_final_formx(char *str, t_struct *t)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;
	char	*final;

	i = 0;
	j = t->nbp;
	k = ft_strlen(str);
	if (j == 0 && t->i == 0)
		return (ft_strnew(1));
	if (k < j)
	{
		tmp = ft_strnew(j - k);
		while (i < j - k)
		{
			tmp[i] = '0';
			i++;
		}
		final = ft_strjoin(tmp, str);
		ft_strdel(&tmp);
		return (final);
	}
	else
		return (ft_strdup(str));
}

static char		*ft_this_isnt_even_my_final_form(char *str, t_struct *t)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	i = 0;
	j = t->nbp;
	k = ft_strlen(str);
	if (j == 0 && t->i == 0)
		return (ft_strnew(1));
	if (k < j)
	{
		tmp = ft_strnew(j - k - ft_diese(t));
		while (i < j - k - ft_diese(t))
		{
			tmp[i] = '0';
			i++;
		}
		return (ft_strjoin(tmp, str));
	}
	return (ft_strdup(str));
}

char			*ft_precision(const char *ft, t_struct *t, char *str)
{
	int		i;
	int		j;
	int		len;
	char	*nb;

	j = 0;
	t->nbp = 0;
	i = t->per;
	while (ft[i] != '.' && ft[i])
		i++;
	len = i + 1;
	while (ft[i] != t->spe && ft[i])
	{
		j++;
		i++;
	}
	nb = ft_strsub(ft, len, j);
	t->nbp = ft_atoi(nb);
	ft_strdel(&nb);
	if (t->spe == 'i' || t->spe == 'd' || t->spe == 'D')
		return (ft_this_isnt_even_my_final_formx(str, t));
	else
		return (ft_this_isnt_even_my_final_form(str, t));
}
