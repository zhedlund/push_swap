# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhedlund <zhedlund@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 17:45:30 by zhedlund          #+#    #+#              #
#    Updated: 2023/09/09 14:06:04 by zhedlund         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

SRC =                   sort_stack.c \
                        swap_operations.c \
                          init_nodes.c \
                          sort_three.c \
                          create_stack.c \
                          ft_atol.c \
                          stack_add_node.c \
                          rotate_operations.c \
                          stack_smallest.c \
                          input_is_valid.c \
                          check_dup.c \
                          ft_split.c \
                          main.c \
                          reverse_rotate_op.c \
                          return_lowest_cost.c \
                          stack_last.c \
                          push_swap.c \
                          error_free.c \
                          stack_is_sorted.c \
                          stack_size.c \
                          push_operations.c \

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