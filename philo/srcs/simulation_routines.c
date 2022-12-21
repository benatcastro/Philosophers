/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_routines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:09:25 by bena              #+#    #+#             */
/*   Updated: 2022/12/16 13:41:47 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_philo *philo)
{
	int	r_fork;
	int	l_fork;

	r_fork = pthread_mutex_lock(&philo->fork);
	if (!r_fork)
		print_philo_status(philo, FORK);
	l_fork = pthread_mutex_lock(&philo->prev->fork);
	if (!l_fork)
		print_philo_status(philo, FORK);
	print_philo_status(philo, EATING);
	ft_usleep(philo->tv->tt_eat);
	philo->last_eat = get_time();
	philo->t_eaten++;
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->prev->fork);
}

void	philo_sleep(t_philo *philo)
{
	ft_usleep(philo->tv->tt_sleep);
	print_philo_status(philo, SLEEPING);
}

void	*init_routine(void *philosopher)
{
	t_philo	*philo;

	philo = philosopher;
	if (philo->id % 2 == 0)
		ft_usleep(50);
	while (philo->g_data->sim_running)
	{
		philo_eat(philo);
		philo_sleep(philo);
		print_philo_status(philo, THINKING);
	}
	return (NULL);
}
