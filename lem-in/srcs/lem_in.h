/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:46:48 by jpallard          #+#    #+#             */
/*   Updated: 2018/04/20 15:38:44 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../../libft/libft.h"
# include <limits.h>

typedef struct		s_ant
{
	long long int	nbant;
	int				start;
	int				end;
	int				error;
	int				tube;
	int				first;
	int				fml;
	int				poid;
}					t_ant;

typedef struct		s_lst
{
	void			*content;
	int				y;
	int				x;
	int				start;
	int				end;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_tab
{
	char			*room;
	int				poid;
	int				end;
	char			*voisin;
	struct s_tab	*next;
}					t_tab;

typedef struct		s_lol
{
	t_lst			*lst;
	struct s_lol	*suivant;
}					t_lol;

typedef struct		s_num
{
	char			*room;
	int				poid;
	int				i;
}					t_num;

void				ft_checkant(char *str, t_ant *f);
t_tab				**parsing(t_lst *room, t_ant *f);
t_tab				*initstock(t_tab *fml);
void				skiproom(t_lst **tmp, t_tab **tab);
void				ft_dellst(t_lst **fml);
void				ft_dellstar(t_lst **fml);
void				ft_delltab(t_tab *tab);
t_tab				*ft_delngb(t_tab *tab, t_lst *tube);
t_lst				*ft_lstvoisin(t_tab *fml, t_lst *tmp2);
t_lst				*firstvoisin(t_tab *fml, t_lst *tmp2);
t_lst				*fourmiliere(char *line, t_lst *fml);
t_lst				*ft_checkroom(char *line, t_ant *f, t_lst *room);
t_lst				*ft_checkt(char *line, t_ant *f, t_lst *room, t_lst *tube);
t_ant				*ft_initstruct(t_ant *f);
void				ft_comment(char *line, t_lst *room, t_ant *f);
t_lst				*ft_lstant(char *content);
t_tab				*ft_lstfourm(char *content);
long long int		ft_longatoi(const char *str);
int					ft_countnb(char *str);
void				error(void);
t_lst				*initroom(char *line, char **split, t_ant *f);
void				ft_lstadq(t_lst *alst, t_lst *hell);
void				ft_lstadtube(t_lst *alst, t_lst *hell, t_ant *f);
void				ft_lstadv(t_lst *alst, t_lst *hell);
void				ft_lstadfourm(t_tab *lst, t_tab *hell);
int					ft_lstlon(t_lst *list);
t_lst				*lsttube(t_lst *room, char *line, t_ant *f);
void				equalroom(t_lst *room, char *line, t_ant *f);
int					ft_bfs(t_tab **tab, t_ant *f);
t_lol				*ft_travel(t_tab **tab, t_lol *lst);
void				ft_multipath(t_tab **tab, t_lol *lst, t_ant *f);
int					ft_searchngb(t_lst *tube, char *room);
void				ft_addend(t_lol *lst, t_tab **tab, t_ant *f);
void				ft_lastinit(t_lol *lst);
int					ft_lstlol(t_lol *lst);
void				ft_checkinone(t_tab **lst, t_ant *f, int i);
void				goal(t_lol *lst);
void				goalatstart(t_lol *lst);
void				freeforall(t_tab **tab, t_ant *f);
void				freelol(t_lol *lst);
void				ft_tabcheck(t_tab **tab, t_ant *f);
void				finishit(t_lol *lst);
t_lst				*reading(t_lst **tube, t_lst **room, t_ant *f, char *line);
void				ft_copyvs(char **split, t_tab *fml);
void				ft_copyvslst(char **split, t_tab *fml);
void				ft_copypasta(char **split, int *i, t_tab *fml, int *k);
void				ft_copyadlst(char **split, int *i, t_tab *fml, int *k);
void				ft_path(t_tab *tmp, t_tab **tab, t_lol *tot, t_num *n);
int					whatidoforan(t_lol *lst);
#endif
