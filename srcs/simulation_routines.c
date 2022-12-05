/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_routines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:09:25 by bena              #+#    #+#             */
/*   Updated: 2022/12/05 17:52:40 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



void	philo_eat(t_philo *philo)
{
	int	r_fork;
	int	l_fork;

	r_fork = pthread_mutex_lock(&philo->fork);
	if (philo->prev)
		l_fork = pthread_mutex_lock(&philo->prev->fork);
	if (r_fork && l_fork)
		return ;
	philo->last_eat = get_time();
	ft_usleep(philo->tv->tt_eat);
	philo->status = EATING;
	philo->tv->t_eaten++;
	print_philo_status(philo);
}

void	philo_sleep(t_philo *philo)
{
	ft_usleep(philo->tv->tt_sleep);
	philo->status = SLEEPING;
	print_philo_status(philo);
}

void	*init_routine(void *philosopher)
{
	t_philo	*philo;

	philo = philosopher;
	while (philo->g_data->sim_running)
	{
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}
