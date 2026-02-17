# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/14 18:10:00 by edsole-a          #+#    #+#              #
#    Updated: 2026/02/17 14:31:24 by jbarreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
HEADER      = push_swap.h

SRC         = main.c                stack_builder.c			\
              ps_split.c            bench_mode.c			\
              operations_push.c     operations_reverse.c	\
              operations_rotate.c   operations_swap.c		\
              algorithm_simple.c    algorithm_medium.c		\
              algorithm_complex.c   algorithm_selector.c	\
              utils_generic.c       utils_algorithm.c		\
			  utils_strings.c								\

OBJ         = $(SRC:.c=.o)

GREEN       = \033[0;32m
RED         = \033[0;31m
YELLOW      = \033[0;33m
NC          = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Push_swap compiled successfully!$(NC)"

%.o: %.c $(HEADER)
	@echo "$(YELLOW)Compiling: $<$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(RED)Objects removed.$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Executable removed.$(NC)"

re: fclean all

.PHONY: all clean fclean re