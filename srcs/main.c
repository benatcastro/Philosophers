/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:35:35 by bena              #+#    #+#             */
/*   Updated: 2022/12/06 16:31:08 by becastro         ###   ########.fr       */
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
	while (data.sim_running)
		ft_usleep(1);
	stop_threads(data.philo_lst);
	exit(0);
}
