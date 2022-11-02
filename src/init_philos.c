/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:10:41 by becastro          #+#    #+#             */
/*   Updated: 2022/11/02 17:56:48 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_philo	ft_create_philo(u_int32_t id, t_philo **head)
{
	t_philo	*node;

	node = malloc(sizeof(t_philo));
	memset(node, NULL, sizeof(t_philo));
	node->id = id;
	if (!*head)
		(*head) = node;
	else
		node->next = (*head);
}

void	ft_init_philos(t_data *data)
{
	static u_int32_t	id;
	t_philo				*philos;

	philos = NULL;
	while (data->n_philos--)
	{
		ft_create_philo(id, &philos);
		id++;
	}
}
