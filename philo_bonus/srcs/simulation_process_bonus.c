/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_process_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:07:05 by becastro          #+#    #+#             */
/*   Updated: 2022/12/09 13:09:52 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <signal.h>

void	kill_child_process(t_data *data)
{
	t_philo	*aux;

	aux = data->philo_lst;
	while (aux)
	{
		kill(aux->pid, SIGQUIT);
		aux = aux->next;
		if (aux == data->philo_lst)
			break ;
	}
}
