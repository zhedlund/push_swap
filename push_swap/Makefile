# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zhedlund <zhedlund@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/18 17:45:30 by zhedlund          #+#    #+#              #
#    Updated: 2023/07/18 18:57:46 by zhedlund         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = 
OBJ = $(SRC:c.=.o)

$(NAME)
		$(CC) $(CFLAGS) $(SRC) $(NAME)

all: $(NAME)

clean:
		@rm -rf *.o

fclean:	clean
		@rm -f $(NAME)

re:	fclean all

.PHONY: all, clean, fclean, re