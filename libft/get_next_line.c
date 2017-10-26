/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 12:25:55 by jpallard          #+#    #+#             */
/*   Updated: 2017/01/21 13:18:16 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_makeline(char *lst, char **line)
{
	int		i;
	int		eof;

	eof = 0;
	i = 0;
	if (lst[i] != '\0')
	{
		while (lst[i] != DELIMITER && lst[i])
			i++;
		if (lst[i] == '\0')
			eof = 1;
		lst[i] = '\0';
		*line = ft_strnew(i);
		*line = ft_strcpy(*line, lst);
		lst = ft_strcpy(lst, &lst[i + 1]);
		if (eof == 1)
			lst[0] = '\0';
		return (1);
	}
	return (0);
}

static t_list	*ft_find_fd(t_list *list, int fd)
{
	t_list	*new;
	t_list	*tmp;

	tmp = NULL;
	if (list == NULL)
	{
		list = ft_lstnew(NULL, fd);
		list->content_size = fd;
		list->content = ft_strnew(0);
		return (list);
	}
	while (list)
	{
		tmp = list;
		if (list->content_size == (unsigned int)fd)
			return (list);
		list = list->next;
	}
	list = tmp;
	new = ft_lstnew(NULL, fd);
	new->content_size = fd;
	new->content = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	list->next = new;
	return (new);
}

static int		ft_read(t_list *list, int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*line;
	int		ret;
	char	*tmp;

	line = NULL;
	tmp = list->content;
	while (line == NULL && (ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = 0;
		line = ft_strchr(buff, DELIMITER);
		list->content = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
		tmp = list->content;
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list = NULL;
	t_list			*tmp;

	tmp = NULL;
	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	tmp = list;
	list = ft_find_fd(list, fd);
	if (ft_read(list, fd) == -1)
		return (-1);
	if (ft_makeline(list->content, line))
	{
		if (tmp)
			list = tmp;
		return (1);
	}
	if (tmp)
		list = tmp;
	return (0);
}
