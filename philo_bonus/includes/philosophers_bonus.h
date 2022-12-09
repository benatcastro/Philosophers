/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:29:12 by bena              #+#    #+#             */
/*   Updated: 2022/12/09 19:04:06 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include "structs_bonus.h"
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <semaphore.h>
# include <stdbool.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>

# define T_USLEEP 50
# define SEM_PERMS 0644
/********SEMAPHORES****************/
# define SEM_SIM_RUNNING	"sim_running"
# define SEM_CREATE_PROCESS	"init_childs"
# define SEM_FORKS			"sem_forks"
# define SEM_PRINT			"print_sem"
# define SEM_PRINT_STATS	"print_stats"
# define SEM_EATEN			"sem_eaten"
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
void		kill_child_process(t_data *data);
u_int64_t	get_time_diff(struct timeval __time);
#endif
