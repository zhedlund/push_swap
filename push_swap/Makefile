# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 17:45:30 by zhedlund          #+#    #+#              #
#    Updated: 2023/09/14 15:44:59 by zhedlund         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

SRC =                     create_stack.c \
                          error_free.c \
                          init_nodes.c \
                          main.c \
                          push_swap.c \
                          push_operations.c \
                          reverse_rotate_op.c \
                          rotate_operations.c \
                          sort_stack.c \
                          stack_utils.c \
                          swap_operations.c \
                          utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
		@rm -rf *.o

fclean:	clean
		@rm -f $(NAME)

re:	fclean all

.PHONY: all, clean, fclean, re