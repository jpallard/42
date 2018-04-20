# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpallard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/06 15:27:52 by jpallard          #+#    #+#              #
#    Updated: 2018/04/20 15:43:25 by jpallard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

CC = gcc
FLAGS =  -Wall -Wextra -Werror

LIB_PATH = $(INC_PATH)libft/

INC = $(addprefix -I , $(INC_PATH))
INC_PATH = ../

SRC_SWAP = $(addprefix $(SRC_SWAP_PATH), $(SRC_SWAP_FILE))
SRC_SWAP_PATH = ./srcs/
SRC_SWAP_FILE =	main.c\
				ft_checkline.c\
				ft_longatoi.c\
				ft_countnb.c\
				initroom.c\
				lstadq.c\
				ft_lstant.c\
				ft_lstlon.c\
				lsttube.c\
				parsing.c\
				ft_lstvoisin.c\
				ft_dellst.c\
				fourmiliere.c\
				ft_bfs.c\
				ft_delngb.c\
				ft_travel.c\
				ft_multipath.c\
				ft_addend.c\
				goal.c\
				checkinone.c\
				freeforall.c\
				ft_tabcheck.c\
				reading.c\
				ft_endofpars.c\
				whatidoforan.c\

OBJ_SWAP = $(addprefix $(OBJ_SWAP_PATH), $(OBJ_SWAP_FILE))
OBJ_SWAP_PATH = ./obj_lem_in/
OBJ_SWAP_FILE = $(SRC_SWAP_FILE:.c=.o)

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ_SWAP)
	@make -C $(LIB_PATH)
	@$(CC) $(OBJ_SWAP) -L $(LIB_PATH) -lft -o $(NAME)
	@echo "\033[32mMake success.\033[0m"

$(OBJ_SWAP_PATH)%.o: $(SRC_SWAP_PATH)%.c
	@mkdir -p $(OBJ_SWAP_PATH)
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<
	@echo "\033[33mCreat. file $@ ..\033[0m"

clean:
	@make clean -C $(LIB_PATH)
	@rm -rf $(OBJ_SWAP)
	@rm -rf $(OBJ_SWAP_PATH)
	@echo "\033[31mclean success.\033[0m"

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -Rf $(NAME)
	@echo "\033[31mfclean success.\033[0m"

re: fclean all
