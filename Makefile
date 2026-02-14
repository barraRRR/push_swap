# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/14 18:10:00 by edsole-a          #+#    #+#              #
#    Updated: 2026/02/14 18:17:15 by jbarreir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror

# Source files (Update these names to match your actual files)
SRC         = main.c \
              stack_creation/create_stack.c \
			  parsing/ps_atoi.c		parsing/ps_split.c \
              operations/operations_push.c \
              operations/operations_reverse.c \
              operations/operations_rotate.c \
              operations/operations_swap.c \
			  disorder_metric/disorder_metric.c \
			  algorithm/complex/complex.c \
              algorithm/medium/sandglass_sort.c \
			  algorithm/simple/selection_sort.c \
			  algorithm/algo_utils.c \
              utils/utils.c

OBJ         = $(SRC:.c=.o)

# Colors for terminal output
GREEN       = \033[0;32m
RED         = \033[0;31m
YELLOW      = \033[0;33m
NC          = \033[0m

# Default rule
all: $(NAME)

# Link the executable
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Push_swap compiled successfully!$(NC)"

# Compile object files
%.o: %.c
	@echo "$(YELLOW)Compiling: $<$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@rm -f $(OBJ)
	@echo "$(RED)Objects removed.$(NC)"

# Full clean (Objects + Executable)
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Executable removed.$(NC)"

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re