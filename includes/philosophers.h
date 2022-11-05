/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:29:12 by bena              #+#    #+#             */
/*   Updated: 2022/11/05 20:23:42 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>
# include <unistd.h>
# include <strings.h>

# define T_USLEEP 50

typedef struct s_data
{
	u_int32_t	time;
	u_int32_t	n_philos;
	u_int32_t	tt_die;
	u_int32_t	tt_eat;
	u_int32_t	tt_sleep;
	u_int32_t	need_to_eat;
	bool		must_eat;
}	t_data;
typedef struct s_philo
{
	u_int32_t		id;
	bool			l_fork;
	bool			r_fork;
	struct s_philo	*next;
	struct s_philo	*before;
}	t_philo;

/********LIBFT UTILS***************/

int		ft_isdigit(int arg);
int		ft_atoi(const char *nptr);
/********TIME FNCS***************/

void	ft_usleep(u_int32_t msec);
void	*get_time(void *ptr_data);

/***********ARGS*************/

bool	ft_check_args(int argc, char **argv, t_data *data);

/***********NODES*************/
void	philo_add(t_philo **head, t_philo *node);
#endif
