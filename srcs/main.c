/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:35:35 by bena              #+#    #+#             */
/*   Updated: 2022/11/05 21:28:07 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	thread_var;

	(void)thread_var;
	if (!ft_check_args(argc, argv, &data))
		exit (EXIT_FAILURE);

	pthread_create(&thread_var, NULL, get_time, &data);
	while (true)
	{
		//printf("(%u)\n", data.time);
		//ft_usleep(1000);
	}
}
