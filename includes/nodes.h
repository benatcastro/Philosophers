/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:includes/nodes.h
/*   Created: 2022/11/05 20:59:24 by bena              #+#    #+#             */
/*   Updated: 2022/11/07 20:16:30 by bena             ###   ########.fr       */
=======
/*   Created: 2022/09/01 11:10:41 by becastro          #+#    #+#             */
/*   Updated: 2022/11/03 14:09:19 by becastro         ###   ########.fr       */
>>>>>>> 7cf60b3 (tests):src/init_philos.c
/*                                                                            */
/* ************************************************************************** */

#ifndef NODES_H
# define NODES_H

<<<<<<< HEAD:includes/nodes.h
# include "structs.h"

t_philo	*ft_philolast(t_philo *lst);
void	ft_philoadd_back(t_philo **lst, t_philo *new);
t_philo	*create_philo_node(u_int32_t id, t_data *data);

#endif
=======
static t_philo	*ft_create_philo(u_int32_t id)
{
	t_philo	*node;

	node = malloc(sizeof(t_philo));
	memset(node, 0, sizeof(t_philo));
	node->id = id;
	node->next = NULL;
	return (node);
}

void	ft_init_philos(t_data *data)
{
	static u_int32_t	id;

	while (data->n_philos--)
	{
		id++;
		ft_create_philo(id);
	}
}
>>>>>>> 7cf60b3 (tests):src/init_philos.c
