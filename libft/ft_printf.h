/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpallard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:31:33 by jpallard          #+#    #+#             */
/*   Updated: 2017/03/23 15:33:27 by jpallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"
# include <wchar.h>

typedef struct		s_struct
{
	char			*str;
	int				spe;
	int				c;
	int				i;
	int				point;
	int				pos;
	int				nneg;
	int				per;
	int				neg;
	int				zero;
	int				diese;
	int				space;
	int				nbl;
	int				nbp;
}					t_struct;

typedef struct		s_conv
{
	int				j;
	int				z;
	int				ch;
	int				cl;
	unsigned int	mask1;
	unsigned int	mask2;
	unsigned int	mask3;
	int				size;
	int				exe;
}					t_conv;

int					ft_printf(const char *format, ...);
void				printd(va_list ap, t_struct *t, const char *ft, t_conv *p);
void				ft_prints(char *str, const char *ft, t_struct *t);
void				ft_printp(void *ptr, t_struct *t);
void				ft_printc(int c, t_struct *t);
void				ft_printper(t_struct *t);
void				ft_puni(va_list ap, t_struct *t, t_conv *p, const char *ft);
void				ft_pus(va_list ap, t_struct *t, t_conv *p, const char *ft);
void				ft_length(const char *ft, t_struct *t, t_conv *p, int i);
void				ft_flag(const char *ft, t_struct *t, int i);
char				*ft_space(char *str, t_struct *t);
char				*ft_spacealt(char *str, t_struct *t);
void				ft_spec(const char *ft, va_list ap, t_struct *t, t_conv *p);
void				ft_sped(const char *ft, va_list ap, t_struct *t, t_conv *p);
int					ft_diese(t_struct *t);
int					ft_chara(const char *ft, int i, t_struct *t);
int					ft_charlen(wint_t n, t_struct *t);
char				*ft_width(unsigned long int n, int base, t_struct *t);
char				*ft_widthx(unsigned long int n, int base, t_struct *t);
int					ft_wstrlen(wchar_t *s, t_struct *t);
void				ft_wcharnul(t_struct *t);
char				*ft_putcbr(long long int n, t_struct *t, int pos);
char				*ft_putcbrx(unsigned long int n, t_struct *t);
char				*ft_precision(const char *ft, t_struct *t, char *str);
char				*ft_precisions(const char *ft, t_struct *t, char *str);
void				ft_binone(t_struct *t, t_conv *p, wint_t n);
void				ft_base(va_list ap, t_struct *t, const char *ft, t_conv *p);
void				base1(va_list ap, t_struct *t, const char *ft, t_conv *p);
void				base2(va_list ap, t_struct *t, const char *ft, t_conv *p);
void				base3(va_list ap, t_struct *t, const char *ft, t_conv *p);
void				ft_end(va_list ap, t_struct *t, const char *ft, t_conv *p);
void				ft_end1(va_list ap, t_struct *t, const char *ft, t_conv *p);
void				ft_end2(va_list ap, t_struct *t, const char *ft, t_conv *p);
void				ft_end3(va_list ap, t_struct *t, const char *ft, t_conv *p);
void				ft_checknb(char const *ft, t_struct *t);
char				*ft_check(t_struct *t, char *str);
char				*ft_checkid(t_struct *t, char *str);
void				ft_allinone(const char *ft, t_struct *t, char *str);
void				ft_allinoneid(const char *ft, t_struct *t, char *str);
int					ft_error(t_struct *t);

#endif
