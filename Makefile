# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/16 12:37:14 by adrianda          #+#    #+#              #
#    Updated: 2026/07/16 16:48:45 by adrianda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

LIB_DIR = lib_ft
LIBFT = $(LIB_DIR)/libft.a

SRCS = src/main.c

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIB_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c // para fazer o main.o use o main.c 
	$(CC) $(CFLAGS) -c $< -o $@ // Se Make precisar compilar src/main.c para src/main.o transforme nisso : cc -Wall -Wextra -Werror -c src/main.c -o src/main.o

clean:
	rm -f $(OBJS)
	make clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re