# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abassibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 12:45:46 by abassibe          #+#    #+#              #
#    Updated: 2017/10/03 05:25:24 by abassibe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRCS =	srcs/checker.c \
		srcs/operations.c \
		srcs/operations2.c \
		srcs/utils.c

OBJS = objs/checker.o \
	   objs/operations.o \
	   objs/operations2.o \
	   objs/utils.o

SRCPATH = ./srcs/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@gcc $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $< -I includes

.PHONY: all clean fclean re

clean:
	@make -C libft clean
	@rm -rf $(addprefix objs/, $(OBJS))

fclean: clean
	@make -C libft fclean
	@rm -rf libft/libft.a $(NAME)

re: fclean all
