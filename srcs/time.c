/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:04:57 by becastro          #+#    #+#             */
/*   Updated: 2022/12/07 19:25:17 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(u_int32_t msec)
{
	return ((void)usleep(msec * 1000));
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
