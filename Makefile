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
	$(CC) $(CFLAGS) $(INC_DIR)*.c -o $(NAME)

sanitize:
	$(CC) $(CFLAGS) $(SANITIZE) $(INC_DIR)*.c -o $(NAME)

valgrind:
	@$(VALGRIND) ./NAME

run:
	@./$(NAME)

clean:

fclean:

re:

.PHONY all sanitize valgrind run clean fclean
