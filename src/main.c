/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:35:35 by bena              #+#    #+#             */
/*   Updated: 2022/08/30 23:42:28 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


/**
 * @brief Get the time object
 * @param data
 * @param ref otro parametro
 */
static void	*get_time(void *ptr_data)
{
	struct timeval	time;
	t_data			*data;
	void			*ret;

	data = ptr_data;
	(void)time;
	printf("time: (%d)\n", data->time);
	while (42)
	{
		// gettimeofday(&time, NULL);
		// data->time = (time.tv_sec * 1000 + time.tv_usec / 1000);
	}
	return (ret);
}

int	main(void)
{
	t_data		data;
	pthread_t	test;

	pthread_create(&test, NULL, get_time, &data);
	printf("hello world\n");
}
