/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_logic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:33:52 by bena              #+#    #+#             */
/*   Updated: 2022/12/05 14:39:14 by becastro         ###   ########.fr       */
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
		if (aux->tv->t_eaten == data->eat_times)
			counter++;
		else
			counter = 0;
		aux = aux->next;
	}
	data->simulation_state = PHILO_EATEN;
	print_simulation_state(data);
	exit(EXIT_SUCCESS);
	//data->sim_running = false;
	return (NULL);
}
