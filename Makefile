# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/14 18:10:00 by edsole-a          #+#    #+#              #
#    Updated: 2026/02/19 11:41:17 by jbarreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
HEADER      = push_swap.h

SRC         = main.c                			parsing/stack_builder.c			\
              utils/ps_split.c            		bench/bench_mode.c			\
              operations/operations_push.c     	operations/operations_reverse.c	\
              operations/operations_rotate.c   	operations/operations_swap.c		\
              algorithm/algorithm_simple.c    	algorithm/algorithm_medium.c		\
              algorithm/algorithm_complex.c   	algorithm/algorithm_selector.c	\
              utils/utils_generic.c       		utils/utils_algorithm.c		\
			  utils/utils_strings.c								\

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