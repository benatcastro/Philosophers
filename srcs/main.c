/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:35:35 by bena              #+#    #+#             */
/*   Updated: 2022/12/05 17:00:31 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data		data;

	memset(&data, 0, sizeof(t_data));
	data.data_tv = malloc(sizeof(t_times));
	data.philo_lst = NULL;
	if (!ft_check_args(argc, argv, &data))
		exit (EXIT_FAILURE);
	init_philos(&data);
	// printf("Test %d\n", data.n_philos);
	while (data.sim_running)
		ft_usleep(1);
	stop_threads(data.philo_lst);
	exit(0);
}
