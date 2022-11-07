/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:04:57 by becastro          #+#    #+#             */
/*   Updated: 2022/11/07 09:00:12 by bena             ###   ########.fr       */
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
u_int32_t	get_time(void)
{
	struct timeval		time;
	static bool			check;
	static u_int32_t	tmp;

	gettimeofday(&time, NULL);
	if (!check)
	{
		tmp = (time.tv_sec * 1000 + time.tv_usec / 1000);
		check = true;
	}
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - tmp);
}
