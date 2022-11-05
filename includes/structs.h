/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:00:49 by bena              #+#    #+#             */
/*   Updated: 2022/11/05 21:24:54 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

/********DEFINES******/
# include <stdlib.h>
# include <stdbool.h>

/********STRUCTS*****/
typedef struct s_philo
{
	u_int32_t		id;
	bool			l_fork;
	bool			r_fork;
	struct s_philo	*next;
	struct s_philo	*prev;
}	t_philo;
typedef struct s_data
{
	u_int32_t	time;
	u_int32_t	n_philos;
	u_int32_t	tt_die;
	u_int32_t	tt_eat;
	u_int32_t	tt_sleep;
	u_int32_t	need_to_eat;
	t_philo		**lst_head;
	bool		must_eat;
}	t_data;


#endif
