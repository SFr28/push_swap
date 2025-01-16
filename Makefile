# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfraslin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/09 14:27:33 by sfraslin          #+#    #+#              #
#    Updated: 2025/01/09 18:11:52 by sfraslin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = ./srcs/push_swap.c ./srcs/pile_functions.c ./srcs/arg_to_pile.c ./srcs/errors.c \
		./srcs/instruction.c ./srcs/ft_atol.c ./srcs/sort.c ./srcs/find.c
OBJS = $(SRCS:.c=.o)
HEADER = -I ./includes/

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT = ./libft/libft.a
LIBPRINTF = ./printf/libftprintf.a

all: $(NAME)

$(NAME) : $(LIBFT) $(LIBPRINTF) $(OBJS)
		$(CC) $(OBJS) $(LIBFT) $(LIBPRINTF) $(HEADER) -o $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(LIBFT):
		make bonus --no-print-directory -C ./libft/

$(LIBPRINTF):
		make --no-print-directory -C ./printf/

clean:
		rm -f $(OBJS)
		make clean --no-print-directory -C ./libft
		make clean --no-print-directory -C ./printf

fclean: clean
		rm -f $(NAME)
		make fclean --no-print-directory -C ./libft
		make fclean --no-print-directory -C ./printf

re: fclean all

.PHONY: all clean flcean re
