/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_routines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:09:25 by bena              #+#    #+#             */
/*   Updated: 2022/12/05 14:37:57 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



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
	}
	return (NULL);
}
