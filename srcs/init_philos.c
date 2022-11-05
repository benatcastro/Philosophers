/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:10:41 by becastro          #+#    #+#             */
/*   Updated: 2022/11/05 21:35:39 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include "nodes.h"

void	ft_init_philos(t_data *data)
{
	static u_int32_t	id;
	t_philo		*philo_head;

	data->lst_head = &philo_head;
	while (data->n_philos--)
	{
		philo_add(&philo_head, create_philo_node(id));
		id++;
	}
}
