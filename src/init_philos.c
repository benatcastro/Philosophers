/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:10:41 by becastro          #+#    #+#             */
/*   Updated: 2022/09/01 11:25:23 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_philo	ft_create_philo(u_int32_t id)
{
	t_philo	*node;

	memset(node, NULL, sizeof(t_philo));
	node->id = id;
	node->next = NULL;
}

void	ft_init_philos(t_data *data)
{
	static u_int32_t	id;
	while (data->n_philos--)
	{
		ft_create_philo(id);
		id++;

	}
}
