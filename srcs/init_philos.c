/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:10:41 by becastro          #+#    #+#             */
/*   Updated: 2022/11/07 09:03:39 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "nodes.h"

void	init_treadhs(t_data *data)
{
	(void)data;
}

void	ft_init_philos(t_data *data)
{
	static u_int32_t	id;
	t_philo				*philo_head;

	philo_head = NULL;
	data->lst_head = &philo_head;

	while (data->n_philos--)
	{
		id++;
		ft_philoadd_back(&philo_head, create_philo_node(id, data->data_tv));
	}
	philo_head->prev = ft_philolast(philo_head);
	ft_philolast(philo_head)->next = philo_head;
}
