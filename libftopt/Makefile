# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: glafitte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/19 11:11:25 by glafitte          #+#    #+#              #
#    Updated: 2015/06/02 23:28:28 by glafitte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libftopt.a
CFLAGS = -Wall -Wextra -Werror -g -I includes/
CC = gcc
SRCS =	src/error.c \
		src/fprintf.c \
		src/free.c \
		src/ft_atoi.c \
		src/ft_bzero.c \
		src/ft_itoa.c \
		src/ft_memalloc.c \
		src/ft_option.c \
		src/ft_strcmp.c \
		src/ft_strdup.c\
		src/ft_strlen.c \
		src/ft_strnew.c \
		src/list.c \
		src/tab.c \
		\

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	@echo "\033[35;1m• \033[0mCompilation de $(NAME) ...\033[55G\c"
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

OBJ : $(OBJ)
	$(CC) $(CFLAGS) $< -c $(SRCS)

clean :
	@echo "\033[35;1m• \033[0mRemoving object files ...\033[55G\c"
	@rm -rf $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

fclean : clean
	@echo "\033[35;1m• \033[0mRemoving $(NAME) ...\033[55G\c"
	@rm -rf $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re : fclean all
