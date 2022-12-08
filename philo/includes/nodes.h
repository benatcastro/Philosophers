/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:59:24 by bena              #+#    #+#             */
/*   Updated: 2022/11/07 20:16:30 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODES_H
# define NODES_H

# include "structs.h"

t_philo	*ft_philolast(t_philo *lst);
void	ft_philoadd_back(t_philo **lst, t_philo *new);
t_philo	*create_philo_node(u_int32_t id, t_data *data);

#endif
