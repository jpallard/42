# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpallard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/18 16:53:55 by jpallard          #+#    #+#              #
#    Updated: 2017/06/23 17:47:18 by jpallard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  ft_base.c \
	   ft_allinone.c \
	   ft_chara.c \
	   ft_check.c \
	   ft_end.c \
	   ft_length.c \
	   ft_precision.c \
	   ft_precisions.c \
	   ft_printper.c \
	   ft_printc.c \
	   printd.c \
	   ft_printf.c \
	   ft_printp.c \
	   ft_prints.c \
	   ft_print_uni.c \
	   ft_print_uni_string.c \
	   ft_putcbr.c \
	   ft_putcbrx.c \
	   ft_space.c \
	   ft_spacealt.c \
	   ft_spec.c \
	   ft_wcharnul.c \
	   ft_width.c \
	   ft_widthx.c \
	   ft_wstrlen.c \
	   ft_error.c \
	   ft_binone.c \
	   ft_strsub.c \
	   ft_strnew.c \
	   ft_strlen.c \
	   ft_strjoin.c \
	   ft_strdup.c \
	   ft_putstr.c \
	   ft_strdel.c \
	   ft_strchr.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_atoi.c \
	   ft_putchar.c \
	   ft_bzero.c \
	   ft_strcpy.c \
	   ft_strcat.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_itoa.c \
	   ft_memccpy.c \
	   ft_memchr.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strtrim.c \
	   ft_strstr.c \
	   ft_strsplit.c \
	   ft_strrchr.c \
	   ft_strnstr.c \
	   ft_strnew.c \
	   ft_strnequ.c \
	   ft_strncpy.c \
	   ft_strncmp.c \
	   ft_strncat.c \
	   ft_strmapi.c \
	   ft_strmap.c \
	   ft_strlcat.c \
	   ft_striteri.c \
	   ft_striter.c \
	   ft_strequ.c \
	   ft_strcmp.c \
	   ft_strclr.c \
	   ft_putnbr.c \
	   ft_putendl_fd.c \
	   ft_putstr_fd.c \
	   ft_putnbr_fd.c \
	   ft_putendl.c \
	   ft_putchar_fd.c \
	   ft_memset.c \
	   ft_memmove.c \
	   ft_memcpy.c \
	   ft_memcmp.c \
	   ft_lstadd.c \
	   ft_lstdel.c \
	   ft_lstdelone.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_lstnew.c \
	   ft_swap.c \
	   ft_foreach.c \
	   ft_print_list.c \
	   ft_print_list_fd.c \
	   ft_lstlen.c \
	   get_next_line.c \

NAME = libft.a

CC = gcc

CFLAGS = -g -Werror -Wall -Wextra

OBJ =  $(SRC:.c=.o)

.PHONY : all, clean, fclean, re

all: $(NAME)

$(NAME) :
	@$(CC) $(CFLAG) -c $(SRC)
	@ar rc $(NAME) $(OBJ)

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
