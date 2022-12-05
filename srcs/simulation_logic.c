/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_logic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:33:52 by bena              #+#    #+#             */
/*   Updated: 2022/12/05 16:47:08 by becastro         ###   ########.fr       */
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
	u_int32_t	philo_counter;

	data = data_ptr;
	philo_counter = data->n_philos;
	aux = (*data->philo_lst);
	while (aux)
	{
		// printf("eaten philos: %d p_counter %d ", data->eaten_philos, philo_counter);
		// printf("id: %d t_eaten: %d e_t %d finis %d\n", aux->id, aux->tv->t_eaten, data->eat_times, aux->finished_eaten);
		if (aux->tv->t_eaten >= data->eat_times && !aux->finished_eaten)
		{
			 printf("id: %d enters\n", aux->id);
			// printf("eaten philos: %d p_counter %d ", data->eaten_philos, philo_counter);
			aux->finished_eaten = true;
			data->eaten_philos++;
		}
		//printf("counter: %d n %d\n", counter, philo_counter);
		if (data->eaten_philos == philo_counter)
			break ;
		aux = aux->next;
	}
	printf("id: %d t_eaten: %d e_t %d finis %d ", aux->id, aux->tv->t_eaten, data->eat_times, aux->finished_eaten);
	printf("counter: %d p_counter %d\n", data->eaten_philos, philo_counter);
	data->sim_running = false;
	data->simulation_state = PHILO_EATEN;
	print_simulation_state(data);
	exit(1);
	//data->sim_running = false;
	return (NULL);
}
