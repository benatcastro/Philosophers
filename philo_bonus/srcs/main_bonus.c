/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:35:35 by bena              #+#    #+#             */
/*   Updated: 2022/12/09 15:05:18 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	memset(data, 0, sizeof(t_data));
	data->data_tv = malloc(sizeof(t_times));
	data->philo_lst = NULL;
	if (!ft_check_args(argc, argv, data))
		return (free(data->data_tv), free(data), EXIT_FAILURE);
	init_philos(data);
	while (data->sim_running)
		ft_usleep(1);
	free_mem(data->philo_lst, data);
}
