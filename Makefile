# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bena <bena@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 21:01:08 by becastro          #+#    #+#              #
#    Updated: 2022/08/30 23:39:01 by bena             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

#debug
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
SANITIZE = -fsanitize=address -g3

#directories
INC_DIR	= -I includes/
SRC_DIR	= src/

all:
	@$(CC) $(CFLAGS) $(SRC_DIR)*.c $(INC_DIR) -o $(NAME)

sanitize:
	@$(CC) $(CFLAGS) $(SRC_DIR) $(SANITIZE) $(INC_DIR)*.c -o $(NAME)

valgrind:
	@$(VALGRIND) ./NAME

run: all
	@./$(NAME)



