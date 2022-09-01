/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 21:29:12 by bena              #+#    #+#             */
/*   Updated: 2022/09/01 08:15:30 by becastro         ###   ########.fr       */
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
enum e_args
{
	N_PHILO,
	N_EATS,
	TT_DIE,
	TT_EAT,
	TT_SLEEP,
};

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

/********LIBFT UTILS***************/

int		ft_isdigit(int arg);
int		ft_atoi(const char *nptr);
/********TIME FNCS***************/

void	ft_usleep(u_int32_t msec);
void	*get_time(void *ptr_data);

/***********ARGS*************/

void	ft_check_args(int argc, char **argv);
#endif
