/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:29:12 by bena              #+#    #+#             */
/*   Updated: 2022/11/07 20:44:24 by bena             ###   ########.fr       */
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


/********LIBFT UTILS***************/

int			ft_isdigit(int arg);
int			ft_atoi(const char *nptr);
/********TIME FNCS***************/

void		ft_usleep(u_int32_t msec);
u_int32_t	get_time(void);

/***********ARGS*************/

bool		ft_check_args(int argc, char **argv, t_data *data);
/*********PHILO LOGIC*******/

void		init_philos(t_data *data);
void		print_philos(t_data *data);
void		*init_routine(void *philosopher);
void		print_philo_status(t_philo *philo);
void		*times_eaten_checker(void *data_ptr);
#endif
