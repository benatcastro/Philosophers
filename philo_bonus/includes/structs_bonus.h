/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:00:49 by bena              #+#    #+#             */
/*   Updated: 2022/12/08 16:49:37 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_BONUS_H
# define STRUCTS_BONUS_H

/********DEFINES******/
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include "semaphore.h"


enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	FORK,
};

enum e_sim_states
{
	DEF_RUNNING,
	PHILO_DIED,
	PHILO_EATEN,
};

/********STRUCTS*****/

typedef struct s_times
{
	int32_t		tt_die;
	int32_t		tt_eat;
	int32_t		tt_sleep;
}	t_times;
typedef struct s_philo
{
	u_int32_t		id;
	pid_t			pid;
	int32_t			last_eat;
	u_int32_t		t_eaten;
	bool			finished_eaten;
	pthread_mutex_t	fork;
	struct s_data	*g_data;
	struct s_times	*tv;
	struct s_philo	*next;
	struct s_philo	*prev;
}	t_philo;
typedef struct s_data
{
	sem_t			*init_childs;
	u_int32_t		n_philos;
	u_int32_t		eaten_philos;
	u_int8_t		simulation_state;
	bool			must_eat;
	bool			sim_running;
	struct s_philo	*philo_lst;
	struct s_times	*data_tv;
	u_int32_t		eat_times;
	pthread_mutex_t	printing;
}	t_data;

#endif
