/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_logic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:33:52 by bena              #+#    #+#             */
/*   Updated: 2022/12/05 17:01:45 by becastro         ###   ########.fr       */
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
	if(!data->must_eat)
		exit(EXIT_FAILURE);
	while (aux)
	{
		// printf("eaten philos: %d p_counter %d ", data->eaten_philos, philo_counter);
		// printf("id: %d t_eaten: %d e_t %d finis %d\n", aux->id, aux->tv->t_eaten, data->eat_times, aux->finished_eaten);
		if (aux->tv->t_eaten >= data->eat_times && !aux->finished_eaten)
		{
			//  printf("id: %d enters\n", aux->id);
			// printf("eaten philos: %d p_counter %d ", data->eaten_philos, philo_counter);
			aux->finished_eaten = true;
			data->eaten_philos++;
		}
		//printf("counter: %d n %d\n", counter, philo_counter);
		if (data->eaten_philos == philo_counter)
			break ;
		aux = aux->next;
	}
	data->simulation_state = PHILO_EATEN;
	print_simulation_state(data);
	return (NULL);
}

void	stop_threads(t_philo **head)
{
	t_philo	*aux;

	aux = (*head);
	while (aux)
	{
		pthread_join(aux->th_id, NULL);
		aux = aux->next;
		if (aux == (*head))
			return ;
	}
}
