/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:10:41 by becastro          #+#    #+#             */
/*   Updated: 2022/12/05 17:48:56 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "nodes.h"
#include <pthread.h>

void	init_treadhs(t_philo **head, t_data *data)
{
	t_philo		*aux;
	pthread_t	eatean_th;
	pthread_t	death_th;

	aux = (*head);
	while (aux)
	{
		pthread_create(&aux->th_id, NULL, init_routine, (void *)aux);
		pthread_mutex_init(&aux->fork, NULL);
		aux = aux->next;
		if (aux == (*head))
			break ;
	}
	pthread_create(&death_th, NULL, death_checker, (void *)data);
	pthread_create(&eatean_th, NULL, times_eaten_checker, (void *)data);
	pthread_mutex_init(&data->printing, NULL);
}

void	init_philos(t_data *data)
{
	static u_int32_t	id;
	t_philo				*philo_head;
	u_int32_t			i;

	i = data->n_philos;
	philo_head = NULL;
	while (i--)
	{
		id++;
		ft_philoadd_back(&philo_head, create_philo_node(id, data));
	}
	philo_head->prev = ft_philolast(philo_head);
	ft_philolast(philo_head)->next = philo_head;
	data->philo_lst = &philo_head;
	data->sim_running = true;
	init_treadhs(&philo_head, data);
}
