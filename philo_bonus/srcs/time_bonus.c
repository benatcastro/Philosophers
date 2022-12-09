/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:04:57 by becastro          #+#    #+#             */
/*   Updated: 2022/12/09 18:56:41 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

u_int64_t	get_time_diff(struct timeval __time)
{
	struct timeval	diff;
	u_int64_t		time;
	u_int64_t		diff_time;

	gettimeofday(&diff, NULL);
	time = (__time.tv_sec * 1000 + __time.tv_usec / 1000);
	diff_time = (diff.tv_sec * 1000 + diff.tv_usec / 1000);
	return (diff_time - time);
}

void	ft_usleep(u_int32_t msec)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	while (msec > get_time_diff(time))
		usleep(50);
}

/**
 * @brief Returns the current timestamp
 * @param data -> data struct
 */
int32_t	get_time(void)
{
	struct timeval		time;
	static bool			check;
	static int32_t		tmp;

	gettimeofday(&time, NULL);
	if (!check)
	{
		tmp = (time.tv_sec * 1000 + time.tv_usec / 1000);
		check = true;
	}
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - tmp);
}
