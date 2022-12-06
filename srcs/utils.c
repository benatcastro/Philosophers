/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 01:59:02 by bena              #+#    #+#             */
/*   Updated: 2022/12/06 17:49:59 by becastro         ###   ########.fr       */
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

void	free_mem(t_philo **head, t_data *data)
{
	t_philo	*aux;
	t_philo	*temp;

	(void)data;
	aux = (*head);
	while (aux)
	{
		temp = aux;
		aux = aux->next;
		free(temp);
		if (aux == (*head))
			break ;
	}
	//free(data->data_tv);
}
