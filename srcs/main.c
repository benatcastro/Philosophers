/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:35:35 by bena              #+#    #+#             */
/*   Updated: 2022/11/07 21:07:43 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	eat_checker;

	memset(&data, 0, sizeof(t_data));
	memset(&data.data_tv, 0, sizeof(t_times));
	data.philo_lst = NULL;
	if (!ft_check_args(argc, argv, &data))
		exit (EXIT_FAILURE);
	init_philos(&data);
	if (data.must_eat)
		pthread_create(&eat_checker, NULL, times_eaten_checker, &data);
	while (data.sim_running)
		pause();
}
