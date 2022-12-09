/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_routines_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:09:25 by bena              #+#    #+#             */
/*   Updated: 2022/12/08 16:49:09 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
	sem_wait(philo->g_data->init_childs);
	sem_post(philo->g_data->init_childs);
	if (philo->id % 2 == 0)
		ft_usleep(50);
	while (philo->g_data->sim_running)
	{
		philo_eat(philo);
		philo_sleep(philo);
	}
	exit(EXIT_SUCCESS);
	return (NULL);
}
