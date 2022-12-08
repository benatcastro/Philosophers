all:
	make --no-print-directory -C philo/

clean:
	make clean --no-print-directory -C philo/

re:
	make re --no-print-directory -C philo/

clean:
	make clean --no-print-directory -C philo/

fclean:
	make fclean --no-print-directory -C philo/
bonus:
	make --no-print-directory -C philo_bonus/

re_bonus:
	make re --no-print-directory -C philo_bonus

clean_bonus:
	make clean --no-print-directory -C philo_bonus

fclean_bonus:
	make fclean --no-print-directory -C philo_bonus

fclean_all: fclean fclean_bonus
	rm -rf execs/
