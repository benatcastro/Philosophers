/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 01:59:02 by bena              #+#    #+#             */
/*   Updated: 2022/11/02 21:09:32 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (true);
	else
		return (false);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	int		nbr;
	size_t	i;

	nbr = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\f'
		|| nptr[i] == '\r' || nptr[i] == '\n' || nptr[i] == '\v')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		nbr *= 10;
		nbr += (nptr[i] - '0');
		i++;
	}
	return (nbr * sign);
}

void	philo_add(t_philo **head, t_philo *node)
{
	t_philo	*aux;

	if (node)
	{
		if (!*head)
		{
			(*head) = node;
			node->next = node;
			node->before = node;
			return ;
		}
		aux = node;
		while (aux && aux->next->id)
			aux = aux->next;
		aux->next = node;
	}
}
