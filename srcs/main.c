/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:35:35 by bena              #+#    #+#             */
/*   Updated: 2022/11/05 23:33:35 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	thread_var;

	memset(&data, 0, sizeof(t_data));
	data.lst_head = NULL;
	if (!ft_check_args(argc, argv, &data))
		exit (EXIT_FAILURE);

	pthread_create(&thread_var, NULL, get_time, &data);
	ft_init_philos(&data);
	printf("test: (%d\n)", (*data.lst_head)->id);
	//print_philos(&data);
}
