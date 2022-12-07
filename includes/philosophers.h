/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:29:12 by bena              #+#    #+#             */
/*   Updated: 2022/12/07 23:31:01 by bena             ###   ########.fr       */
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

<<<<<<< HEAD
=======
enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
};

typedef struct s_philo
{
	u_int16_t		status;
	u_int32_t		id;
	bool			l_fork;
	bool			r_fork;
	struct s_philo	*next;
}	t_philo;

typedef struct s_data
{
	u_int32_t			time;
	u_int32_t			n_philos;
	u_int32_t			tt_die;
	u_int32_t			tt_eat;
	u_int32_t			tt_sleep;
	u_int32_t			need_to_eat;
	bool				must_eat;
	struct s_philo		**philo_general;
}	t_data;

>>>>>>> 7cf60b3 (tests)
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
