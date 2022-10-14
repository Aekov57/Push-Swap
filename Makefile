# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misimon <misimon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 14:31:22 by misimon           #+#    #+#              #
#    Updated: 2022/10/13 20:29:00 by misimon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAG = -Wall -Werror -Wextra -g3
DANGER = -fsanitize=address
LIBS = -Llibft -lft

# **************************************************************************** #
#                                    FILES                                     #
# **************************************************************************** #

MAIN_SRC = main\

ALL_SRC += $(addsuffix .c, $(MAIN_SRC))

# **************************************************************************** #

SRC = return_fct \

ALL_SRC += $(addprefix src/, $(addsuffix .c, $(SRC)))

OBJS = $(ALL_SRC:.c=.o)

# **************************************************************************** #
#                                    COMMAND                                   #
# **************************************************************************** #

all : $(NAME)

.c.o :
	@$(CC) $(CFLAG) -o $@ -c $<

$(NAME) : $(OBJS)
		@make -sC libft
		@$(CC) -o $(NAME) $(OBJS) $(LIBS)

norm :
		@make norm -sC libft
		@norminette
		@norminette src/*

clean :
		@make clean -sC libft
		@rm -f $(OBJS)

fclean : clean
	@make fclean -sC libft
	@rm -f $(NAME)

re : fclean all