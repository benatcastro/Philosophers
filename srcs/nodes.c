/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:58:15 by bena              #+#    #+#             */
/*   Updated: 2022/12/07 18:43:51 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nodes.h"
#include "structs.h"
#include "philosophers.h"
#include <string.h>
#include <stdio.h>

/*void	print_philos(t_data *data)
{
	t_philo	*aux;

	aux = (*data->lst_head);
	while (aux)
	{
		printf("(%d) Philo: (%d)", get_time(), aux->id);
		if (aux->status == TEST)
			printf(" <TEST>\n");
		ft_usleep(100000);
		aux = aux->next;
	}
}*/

t_philo	*ft_philolast(t_philo *lst)
{
	u_int32_t	start_id;

	if (!lst)
		return (NULL);
	start_id = lst->id;
	while (lst->next)
	{
		lst = lst->next;
		if (start_id == lst->id)
			break ;
	}
	return (lst);
}

void	ft_philoadd_back(t_philo **lst, t_philo *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		new->prev = ft_philolast(*lst);
		ft_philolast(*lst)->next = new;
	}
}

t_philo	*create_philo_node(u_int32_t id, t_data *data)
{
	t_philo	*node;

	node = malloc(sizeof(t_philo));
	memset(node, 0, sizeof(t_philo));
	node->id = id;
	node->tv = data->data_tv;
	node->g_data = data;
	node->finished_eaten = false;
	node->t_eaten = 0;
	node->last_eat = 0;
	return (node);
}
