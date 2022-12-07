# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bena <bena@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 21:01:08 by becastro          #+#    #+#              #
#    Updated: 2022/12/07 23:57:07 by bena             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror #$(SANITIZE)

#debug
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
SANITIZE = -fsanitize=address -g3

#directories
INC_DIR	= includes/
SRC_DIR	= srcs/
OBJ_DIR = objs/
INC_FLAG = -I $(INC_DIR)
SRC_FILES =	args \
			main \
			time \
			utils \
			nodes \
			simulation_routines \
			simulation_logic \
			simulation_init \
			simulation_prints \

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))


all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INC_FLAG) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC_FLAG) -c $< -o $@


clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind:
	@$(VALGRIND) ./NAME

run: all
	@./$(NAME)

bonus:
	make --no-print-directory -C bonus

re_bonus:
	make re --no-print-directory -C bonus

clean_bonus:
	make clean --no-print-directory -C bonus

fclean_bonus:
	make fclean --no-print-directory -C bonus

fclean_all: fclean fclean_bonus

.PHONY: all clean fclean re valgrind run bonus re_bonus clean_bonus fclean_bonus fclean_all

