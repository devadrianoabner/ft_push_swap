# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafcrist <rafcrist@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/16 12:37:14 by adrianda          #+#    #+#              #
#    Updated: 2026/08/06 16:24:29 by rafcrist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilib_ft -Isrc/algorithms/common
# Módulos de pastas
LIB_DIR = lib_ft
LIBFT = $(LIB_DIR)/libft.a
DIR_PARSE = src/parse/
DIR_STACK = src/stack/
DIR_NODE = src/stack/node/
DIR_OPERATIONS = src/operations/
DIR_METRICS = src/metrics/
DIR_INIT = src/init/
DIR_ERROR = src/error/
DIR_COMMON = src/algorithms/common/
DIR_SIMPLE = src/algorithms/simple/
DIR_STRATEGY = src/strategy/
#DIR_MEDIUM = src/algorithms/medium/
#DIR_COMPLEX = src/algorithms/complex/

# Arquivos de módulos
SRC_MAIN = src/main.c
SRC_PARSE = $(DIR_PARSE)validate.c $(DIR_PARSE)flags.c $(DIR_PARSE)parser.c
SRC_STACK = $(DIR_STACK)stack_build.c $(DIR_STACK)stack_inspect.c \
            $(DIR_STACK)stack_free.c
SRC_NODE = $(DIR_NODE)node_inspect.c
SRC_OPERATIONS = $(DIR_OPERATIONS)push.c $(DIR_OPERATIONS)r_reverse.c \
                 $(DIR_OPERATIONS)rotate.c $(DIR_OPERATIONS)swap.c
SRC_METRICS = $(DIR_METRICS)count_op.c $(DIR_METRICS)disorder.c
SRC_INIT = $(DIR_INIT)init_push_swap.c
SRC_ERROR = $(DIR_ERROR)error.c
SRC_COMMON = $(DIR_COMMON)cost.c $(DIR_COMMON)moves.c $(DIR_COMMON)position.c \
             $(DIR_COMMON)sort_three.c $(DIR_COMMON)return_to_a.c
SRC_SIMPLE = $(DIR_SIMPLE)controller.c $(DIR_SIMPLE)sort_push.c
#SRC_MEDIUM = $(DIR_MEDIUM)
#SRC_COMPLEX = $(DIR_COMPLEX)

# Junção de todos os arquivos fonte
SRCS = $(SRC_MAIN) $(SRC_PARSE) $(SRC_STACK) $(SRC_NODE) $(SRC_OPERATIONS) \
       $(SRC_METRICS) $(SRC_SIMPLE) $(SRC_INIT) $(SRC_ERROR) $(SRC_COMMON) \
	   $(SRC_STRATEGY)

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
	make clean -C $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB_DIR)

re: fclean all

.PHONY: all clean fclean re