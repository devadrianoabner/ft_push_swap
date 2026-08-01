# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrianda <adrianda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/16 12:37:14 by adrianda          #+#    #+#              #
#    Updated: 2026/07/23 17:42:31 by adrianda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilib_ft

# Módulos de pastas
LIB_DIR = lib_ft
LIBFT = $(LIB_DIR)/libft.a
DIR_PARSE = src/parse/
DIR_STACK = src/stack/
DIR_NODE = src/stack/node/
DIR_OPERATIONS = src/operations/
DIR_METRICS = src/metrics/
DIR_SIMPLE = src/algorithms/simple/
#DIR_MEDIUM = src/algorithms/medium/
#DIR_COMPLEX = src/algorithms/complex/

# Arquivos de módulos
SRC_MAIN = src/main.c
SRC_PARSE = $(DIR_PARSE)validate.c
SRC_STACK = $(DIR_STACK)stack_build.c $(DIR_STACK)stack_inspect.c 
SRC_NODE = $(DIR_NODE)get_node.c $(DIR_NODE)node_inspect.c 
SRC_OPERATIONS = $(DIR_OPERATIONS)push.c $(DIR_OPERATIONS)r_reverse.c \
                 $(DIR_OPERATIONS)rotate.c $(DIR_OPERATIONS)swap.c
SRC_METRICS = $(DIR_METRICS)count_op.c
SRC_SIMPLE = $(DIR_SIMPLE)controller.c $(DIR_SIMPLE)cost.c $(DIR_SIMPLE)moves.c \
             $(DIR_SIMPLE)position.c $(DIR_SIMPLE)sort_push.c
#SRC_MEDIUM = $(DIR_MEDIUM)
#SRC_COMPLEX =  $(DIR_COMPLEX)

# Junção de todos os arquivos fonte
SRCS = $(SRC_MAIN) $(SRC_PARSE) $(SRC_STACK) $(SRC_NODE) $(SRC_OPERATIONS) \
       $(SRC_METRICS) $(SRC_SIMPLE)

SRCS = $(SRC_MAIN) $(SRC_PARSE) $(SRC_STACK) $(DIR_OPERATIONS) $(DIR_METRICS) \
$(SRC_SIMPLE)

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)


$(LIBFT): f
	make -C $(LIB_DIR)

f:

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