/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:59:24 by bena              #+#    #+#             */
/*   Updated: 2022/12/08 14:44:03 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODES_BONUS_H
# define NODES_BONUS_H

# include "structs_bonus.h"

t_philo	*ft_philolast(t_philo *lst);
void	ft_philoadd_back(t_philo **lst, t_philo *new);
t_philo	*create_philo_node(u_int32_t id, t_data *data);

#endif
