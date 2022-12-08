/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_prints_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:28:19 by becastro          #+#    #+#             */
/*   Updated: 2022/12/08 14:38:56 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	print_philo_status(t_philo *philo, u_int8_t status)
{
	pthread_mutex_lock(&philo->g_data->printing);
	printf("%d %d ", get_time(), philo->id);
	if (status == EATING)
		printf("is eating\n");
	else if (status == SLEEPING)
		printf("is sleeping\n");
	else if (status == THINKING)
		printf("is thinking\n");
	else if (status == FORK)
		printf("has taken a fork\n");
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
		printf("Simulation ended, philo %d died at time %d\n",
			philo->id, get_time());
		data->sim_running = false;
	}
}
