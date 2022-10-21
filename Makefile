# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: misimon <misimon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 00:55:09 by misimon           #+#    #+#              #
#    Updated: 2022/10/21 20:55:18 by misimon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	NAME :
NAME	:= 	push_swap
#	FILE :
SRC_DIR	:= 	src

SRCS	:=	main.c						\
										\
			parsing_fct/arg_check.c		\
										\
			linked_lst_fct/lst_fct.c	\

SRCS := 	$(SRCS:%=$(SRC_DIR)/%)

#	COMPILATION:
CC := 		@gcc
CFLAGS := 	-Wall -Werror -Wextra
LIBS :=		-Llibft -lft
DANGER := -fsanitize=address

#	STATIC LIB CREATION:
AR :=		@ar
ARFLAG :=	-rcs

#	BUILD:
OBJS_DIR := .build
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJS_DIR)/%.o)
LIBFILE := libft

#	TOOLS:

RM	:= @rm -rf
DUP_DIR = @mkdir -p $(@D)
CREATE_DIR = [ ! -d $(OBJS_DIR) ] && mkdir $(OBJS_DIR)
ALLOBJS = $(OBJS_DIR)/%.o

#	COMMAND:

all : $(NAME)

.create.build :
	$(CREATE_DIR)
	$(CLONE_LIB)

$(OBJS_DIR)/%.o : $(SRC_DIR)/%.c
	@make -sC libft
	$(DUP_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<
	@echo "\033[1A\033[0J\033[32;1m\rPush-Swap compilation >>\033[0m\033[30;1m $@\033[0m"

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LIBS) -g

clean :
	@make clean -sC libft
	$(RM) $(OBJS_DIR)

fclean : clean
	@make fclean -sC libft
	$(RM) $(NAME)

re : fclean all
