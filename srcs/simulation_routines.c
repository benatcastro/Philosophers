/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_routines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:09:25 by bena              #+#    #+#             */
/*   Updated: 2022/12/07 19:48:15 by becastro         ###   ########.fr       */
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
	// if (r_fork || l_fork)
	// {
	// 	print_philo_status(philo, THINKING);
	// 	pthread_mutex_unlock(&philo->fork);
	// 	pthread_mutex_unlock(&philo->prev->fork);
	// 	return (philo_eat(philo));
	// }
	philo->last_eat = get_time();
	philo->t_eaten++;
	ft_usleep(philo->tv->tt_eat);
	print_philo_status(philo, EATING);
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
	}
	return (NULL);
}
