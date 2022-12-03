/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:09:25 by bena              #+#    #+#             */
/*   Updated: 2022/12/03 21:32:06 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_philo_status(t_philo *philo)
{
	pthread_mutex_lock(&philo->g_data->printing);
	printf("%d %d ", get_time(), philo->id);
	if (philo->status == EATING)
		printf("is eating\n");
	else if (philo->status == SLEEPING)
		printf("is sleeping\n");
	pthread_mutex_unlock(&philo->g_data->printing);
}

void	philo_eat(t_philo *philo)
{
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
	while (true)
	{
		philo_eat(philo);
		philo_sleep(philo);
	ft_usleep(100000);
	}
	return (NULL);
}
