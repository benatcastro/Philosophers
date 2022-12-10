/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:29:12 by bena              #+#    #+#             */
/*   Updated: 2022/12/10 10:49:50 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "structs.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>
# include <unistd.h>
# include <string.h>

# define T_USLEEP 50

/********PRINT ARGS***************/
# define ARG1 "[number of philosophers]"
# define ARG2 "[time to die]"
# define ARG3 "[time to eat]"
# define ARG4 "[time to sleep]"
# define ARG5 "[numbers of times that each philo has to eat]"
/********PRINT COLORS***************/
# define CBOLD	"\e[1m"
# define BRED "\e[1;31m"
# define CRESET	"\e[m"
/********LIBFT UTILS***************/

void		print_list(t_philo **head);
int			ft_isdigit(int arg);
int			ft_atoi(const char *nptr);
/********TIME FNCS***************/

void		ft_usleep(u_int32_t msec);
int32_t		get_time(void);

/***********ARGS*************/

bool		ft_check_args(int argc, char **argv, t_data *data);
/*********PHILO LOGIC*******/

void		free_mem(t_philo *head, t_data *data);
void		*death_checker(void *data_ptr);
void		stop_threads(t_philo **head);
void		print_simulation_state(t_data *data, t_philo *philo);
void		print_philo_status(t_philo *philo, u_int8_t status);
void		init_philos(t_data *data);
void		print_philos(t_data *data);
void		*init_routine(void *philosopher);
void		*times_eaten_checker(void *data_ptr);
#endif
