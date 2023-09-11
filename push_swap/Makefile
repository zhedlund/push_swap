# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 17:45:30 by zhedlund          #+#    #+#              #
#    Updated: 2023/09/11 15:04:15 by zhedlund         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

SRC =                   sort_stack.c \
                        swap_operations.c \
                          init_nodes.c \
                          create_stack.c \
                          rotate_operations.c \
                          input_is_valid.c \
                          ft_split.c \
                          main.c \
                          reverse_rotate_op.c \
                          push_swap.c \
                          error_free.c \
                          push_operations.c \
                          stack_utils.c \

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