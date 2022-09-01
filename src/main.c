/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:35:35 by bena              #+#    #+#             */
/*   Updated: 2022/09/01 07:45:07 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief Updates the time in the data structure every milisec
 * @param data -> data struct
 */
static void	*get_time(void *ptr_data)
{
	struct timeval	time;
	static bool		check;
	u_int32_t		tmp;
	t_data			*data;

	check = false;
	data = ptr_data;
	(void)time;
	while (true)
	{
		gettimeofday(&time, NULL);
		if (!check)
		{
			tmp = (time.tv_sec * 1000 + time.tv_usec / 1000);
			check = true;
		}
		data->time = (time.tv_sec * 1000 + time.tv_usec / 1000) - tmp;
	}
	return (NULL);
}

int	main(void)
{
	t_data		data;
	pthread_t	thread_var;

	(void)thread_var;
	//ft_usleep(90);
	pthread_create(&thread_var, NULL, get_time, &data);
	while (true)
	{
		printf("(%u)\n", data.time);
		ft_usleep(1000);
	}
}
