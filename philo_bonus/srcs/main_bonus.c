/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:35:35 by bena              #+#    #+#             */
/*   Updated: 2022/12/10 10:42:41 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <signal.h>

int	main(int argc, char **argv)
{
	t_data		*data;

	if (argc == 1)
		return (printf("%sThe program arguments are: %s %s %s %s %s%s\n",
				CBOLD, ARG1, ARG2, ARG3, ARG4, ARG5, CRESET));
	data = malloc(sizeof(t_data));
	memset(data, 0, sizeof(t_data));
	data->data_tv = malloc(sizeof(t_times));
	data->philo_lst = NULL;
	if (!ft_check_args(argc, argv, data))
		return (free(data->data_tv), free(data), EXIT_FAILURE);
	sem_unlink(SEM_SIM_RUNNING);
	data->sim_running = sem_open(SEM_SIM_RUNNING, O_CREAT, SEM_PERMS, 0);
	sem_unlink(SEM_EATEN);
	data->eat_sem = sem_open(SEM_EATEN, O_CREAT, SEM_PERMS, 0);
	init_philos(data);
	sem_wait(data->sim_running);
	kill_child_process(data);
	free_mem(data->philo_lst, data);
	exit(EXIT_SUCCESS);
}
