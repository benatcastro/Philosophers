/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_prints.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:28:19 by becastro          #+#    #+#             */
/*   Updated: 2022/12/10 11:34:43 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		printf("%sSimulation ended, all philos have eaten %d times%s\n",
			CBOLD, data->eat_times, CRESET);
		data->sim_running = false;
	}
	if (data->simulation_state == PHILO_DIED)
	{
		if (data->simulation_state == PHILO_DIED)
			printf("%s%d %d has%s %sdied%s\n",
				CBOLD, get_time(), philo->id,
				CRESET, BRED, CRESET);
		data->sim_running = false;
	}
}
