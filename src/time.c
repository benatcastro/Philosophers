/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:04:57 by becastro          #+#    #+#             */
/*   Updated: 2022/09/01 08:05:13 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(u_int32_t msec)
{
	int	i;
	int	iters;

	i = -1;
	iters = msec / T_USLEEP;
	while (++i < iters)
		usleep(T_USLEEP);
	if (msec % T_USLEEP)
		usleep(msec % T_USLEEP);
}

/**
 * @brief Updates the time in the data structure every milisec
 * @param data -> data struct
 */
void	*get_time(void *ptr_data)
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
