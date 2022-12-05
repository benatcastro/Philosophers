/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_prints.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:28:19 by becastro          #+#    #+#             */
/*   Updated: 2022/12/06 00:07:10 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_philo_status(t_philo *philo)
{
	if (philo->g_data->sim_running == true)
		pthread_mutex_lock(&philo->g_data->printing);
	else
		return ;
	printf("%d %d ", get_time(), philo->id);
	if (philo->status == EATING)
		printf("is eating\n");
	else if (philo->status == SLEEPING)
		printf("is sleeping\n");
	pthread_mutex_unlock(&philo->g_data->printing);
}

void	print_simulation_state(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->printing);
	if (data->simulation_state == PHILO_EATEN)
	{
		printf("Simulation ended, all philos have eaten %d times\n",
			data->eat_times);
		data->sim_running = false;
	}
	if (data->simulation_state == PHILO_DIED)
	{
		printf("Simulation ended, philo %d died at %d\n", philo->id, get_time());
		data->sim_running = false;
	}
}
