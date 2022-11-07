/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:09:25 by bena              #+#    #+#             */
/*   Updated: 2022/11/07 09:47:30 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_philo_status(u_int32_t id, u_int16_t msg_id)
{
	printf("%d %d ", get_time(), id);
	if (msg_id == EATING)
		printf("is eating\n");
	else if (msg_id == SLEEPING)
		printf("is sleeping\n");
}

void	philo_eat(t_philo *philo)
{
	ft_usleep(philo->tv.tt_eat);
	philo->status = EATING;
	philo->tv.t_eaten++;
	print_philo_status(philo->id, philo->status);
}

void	philo_sleep(t_philo *philo)
{
	ft_usleep(philo->tv.tt_sleep);
	philo->status = SLEEPING;
	print_philo_status(philo->id, SLEEPING);
}

void	*init_routine(void *philosopher)
{
	t_philo	*philo;

	philo = philosopher;
	while (true)
	{
		philo_eat(philo);
		philo_sleep(philo);
		ft_usleep(1000000);
	}
	return (NULL);
}
