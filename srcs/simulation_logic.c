/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_logic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:33:52 by bena              #+#    #+#             */
/*   Updated: 2022/11/07 21:08:05 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// bool	death_checker()
// {

// }

void	*times_eaten_checker(void *data_ptr)
{
	t_data		*data;
	t_philo		*aux;
	u_int32_t	counter;

	data = data_ptr;
	aux = (*data->philo_lst);
	counter = 0;
	while (aux && (counter != data->n_philos))
	{
		if (aux->tv.t_eaten == data->eat_times)
			counter++;
		else
			counter = 0;
		aux = aux->next;
	}
	printf("Simulation ended all philosphers haave eaten %d times\n",
		data->eat_times);
	exit(EXIT_SUCCESS);
	//data->sim_running = false;
	return (NULL);
}
