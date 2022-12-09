/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_prints_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:28:19 by becastro          #+#    #+#             */
/*   Updated: 2022/12/09 19:42:31 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include "signal.h"

void	print_philo_status(t_philo *philo, u_int8_t status)
{
	sem_wait(philo->g_data->printing);
	printf("%llu %d ", get_time_diff(philo->g_data->g_time), philo->id);
	if (status == EATING)
		printf("is eating\n");
	else if (status == SLEEPING)
		printf("is sleeping\n");
	else if (status == THINKING)
		printf("is thinking\n");
	else if (status == FORK)
		printf("has taken a fork\n");
	sem_post(philo->g_data->printing);
}

void	print_simulation_state(t_data *data, t_philo *philo)
{
	sem_wait(data->printing);
	if (data->simulation_state == PHILO_EATEN)
		printf("Simulation ended, all philos have eaten %d times\n",
			data->eat_times);
	if (data->simulation_state == PHILO_DIED)
		printf("Simulation ended, philo %d died at time %llu\n",
			philo->id, get_time_diff(data->g_time));
	sem_post(data->sim_running);
	sem_wait(data->global_prints);
	exit(EXIT_SUCCESS);
}
