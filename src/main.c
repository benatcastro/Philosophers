/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:35:35 by bena              #+#    #+#             */
/*   Updated: 2022/09/01 11:25:13 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_philo		*philos;
	pthread_t	thread_var;

	(void)thread_var;
	if (!ft_check_args(argc, argv, &data))
		return (1);
	memset(philos, NULL, sizeof(t_philo));
	data.philo_general = &philos;
	pthread_create(&thread_var, NULL, get_time, &data);
	while (true)
	{
		//printf("(%u)\n", data.time);
		//ft_usleep(1000);
	}
}
