/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_prints.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:28:19 by becastro          #+#    #+#             */
/*   Updated: 2022/12/05 14:38:35 by becastro         ###   ########.fr       */
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

void	print_simulation_state(t_data *data)
{
	if (data->simulation_state == PHILO_EATEN)
	{
		pthread_mutex_lock(&data->printing);
		printf("Simulation ended, all philos have eaten %d times\n",
			data->eat_times);
		exit (EXIT_SUCCESS);
	}
}
