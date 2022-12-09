/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:35:35 by bena              #+#    #+#             */
/*   Updated: 2022/12/09 18:56:28 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <signal.h>

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	memset(data, 0, sizeof(t_data));
	data->data_tv = malloc(sizeof(t_times));
	data->philo_lst = NULL;
	if (!ft_check_args(argc, argv, data))
		return (free(data->data_tv), free(data), EXIT_FAILURE);
	sem_unlink(SEM_SIM_RUNNING);
	data->sim_running = sem_open(SEM_SIM_RUNNING, O_CREAT, SEM_PERMS, 0);
	init_philos(data);
	sem_wait(data->sim_running);
	kill_child_process(data);
	free_mem(data->philo_lst, data);
	exit(EXIT_SUCCESS);
}
