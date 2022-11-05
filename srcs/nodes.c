/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:58:15 by bena              #+#    #+#             */
/*   Updated: 2022/11/05 21:24:06 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nodes.h"
#include "structs.h"

t_philo	*ft_philolast(t_philo *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next || lst->id == 0)
		lst = lst->next;
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
