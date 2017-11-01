# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abassibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 12:45:46 by abassibe          #+#    #+#              #
#    Updated: 2017/11/01 01:31:50 by abassibe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

NAME2 = push_swap

SRCS =	checker.c \
		operations.c \
		operations2.c \
		utils.c

SRCS2 = push_swap.c \
		ope.c \
		ope2.c \
		algo.c \
		visu.c

OBJS = $(SRCS:.c=.o)

OBJS2 = $(SRCS2:.c=.o)

SRCPATH = ./srcs_checker/

SRCPATH2 = ./srcs_pushswap/

FLAGS = -Wall -Wextra -Werror

all: $(NAME) $(NAME2)

$(NAME): $(OBJS)
	@make -C libft
	@gcc $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)

$(NAME2): $(OBJS2)
	@gcc $(FLAGS) $(OBJS2) libft/libft.a ressources/libmlx.a -o $(NAME2) \
		-L. -framework OpenGL -framework AppKit

%.o: $(SRCPATH)%.c
	@gcc $(FLAGS) -c $< -I includes

%.o: $(SRCPATH2)%.c
	@gcc $(FLAGS) -c $< -I includes

.PHONY: all clean fclean re

clean:
	@make -C libft clean
	@rm -rf $(OBJS) $(OBJS2)

fclean: clean
	@make -C libft fclean
	@rm -rf libft/libft.a $(NAME) $(NAME2)

re: fclean all
