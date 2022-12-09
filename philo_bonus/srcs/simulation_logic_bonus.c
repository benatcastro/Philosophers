/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_logic_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:33:52 by bena              #+#    #+#             */
/*   Updated: 2022/12/09 19:49:28 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*death_checker(void *philo_ptr)
{
	t_philo	*philo;

	philo = philo_ptr;
	ft_usleep(50);
	while (true)
	{
		if ((get_time() - philo->last_eat) >= philo->g_data->data_tv->tt_die)
			break ;
	}
	philo->g_data->simulation_state = PHILO_DIED;
	print_simulation_state(philo->g_data, philo);
	return (NULL);
}

void	*times_eaten_checker(void *data_ptr)
{
	t_philo				*philo;
	static u_int32_t	philos_eaten;

	philo = (t_philo *)data_ptr;
	if (!philo->g_data->must_eat)
		return (NULL);
	while (true)
	{
		sem_wait(philo->g_data->eat_sem);
		philos_eaten++;
		if (philo->g_data->n_philos >= philos_eaten)
		{
			philo->g_data->simulation_state = PHILO_EATEN;
			print_simulation_state(philo->g_data, NULL);
		}
		else
			sem_post(philo->g_data->eat_sem);
	}
	return (NULL);
}
