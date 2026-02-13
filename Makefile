# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edsole-a <edsole-a@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/12 17:56:58 by edsole-a          #+#    #+#              #
#    Updated: 2026/02/13 18:21:26 by edsole-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = 	

OBJ = $(SRC:.c=.o)

INCLUDE = push_swap.h 

all: $(NAME)

$(NAME): $(OBJ)	
	ar rcs $(NAME) $(OBJ)
%.o: %.c $(INCLUDE)	Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean	
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re