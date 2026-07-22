# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/22 17:47:31 by adrianda          #+#    #+#              #
#    Updated: 2026/07/22 18:21:18 by adrianda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_ps
CC = cc
CFLAGS = -Wall -Wextra -Werror -I../include -I../lib_ft

LIB_DIR = ../lib_ft
LIBFT = $(LIB_DIR)/libft.a

# Todo .c de src/, menos main.c (senão colide com o main() daqui)
#Uso de wildcard para facilitar a compilação, visto que esse arquivo não será entregue
SRC_FILES = $(filter-out ../src/main.c, $(wildcard ../src/*/*.c))

# Arquivos do diretório de testes
TEST_FILES = main_test.c debug/print_stack.c dummy/build_dummy_stack.c

SRCS = $(SRC_FILES) $(TEST_FILES)
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIB_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re