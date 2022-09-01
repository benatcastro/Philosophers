/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:29:12 by bena              #+#    #+#             */
/*   Updated: 2022/09/01 07:47:16 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>
# include <unistd.h>

# define T_USLEEP 50

typedef struct s_data
{
	u_int32_t	time;

}	t_data;
typedef struct s_philo
{
	u_int32_t		id;
	bool			l_fork;
	bool			r_fork;
	struct s_philo	*next;
}	t_philo;

void	ft_usleep(u_int32_t msec);

#endif
