/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:00:49 by bena              #+#    #+#             */
/*   Updated: 2022/12/03 21:31:07 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/********DEFINES******/
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>

enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TEST,
};

/********STRUCTS*****/

typedef struct s_times
{
	u_int32_t	tt_die;
	u_int32_t	tt_eat;
	u_int32_t	tt_sleep;
	u_int32_t	t_eaten;
}	t_times;
typedef struct s_philo
{
	u_int32_t		id;
	pthread_t		th_id;
	u_int16_t		status;
	bool			l_fork;
	bool			r_fork;
	struct s_data	*g_data;
	struct s_times	*tv;
	struct s_philo	*next;
	struct s_philo	*prev;
}	t_philo;
typedef struct s_data
{

	u_int32_t		n_philos;
	struct s_philo	**philo_lst;
	struct s_times	data_tv;
	bool			must_eat;
	u_int32_t		eat_times;
	pthread_mutex_t	printing;
	bool			sim_running;
}	t_data;


#endif
