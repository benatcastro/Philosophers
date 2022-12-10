/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:09:42 by becastro          #+#    #+#             */
/*   Updated: 2022/12/10 11:02:35 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_declare_values(char **argv, t_data *data, bool need_eat)
{
	data->n_philos = ft_atoi(argv[1]);
	data->data_tv->tt_die = ft_atoi(argv[2]);
	data->data_tv->tt_eat = ft_atoi(argv[3]);
	data->data_tv->tt_sleep = ft_atoi(argv[4]);
	if (need_eat)
	{
		data->must_eat = true;
		data->eat_times = ft_atoi(argv[5]);
	}
}

static bool	ft_check_chars(char **argv)
{
	u_int16_t	i;
	u_int16_t	j;

	i = 0;
	j = -1;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("%sError:%s arg number %d has invalid characters ❌\n",
					BRED, CRESET, i);
				return (false);
			}
		}
	}
	return (true);
}

bool	ft_check_args(int argc, char **argv, t_data *data)
{
	bool		must_eat;

	if (ft_atoi(argv[1]) <= 0)
		return ((void)printf
			("%sError:%s %sthere muest be at least 1 philosopher ❌%s\n",
				BRED, CRESET, CBOLD, CRESET), false);
	if (argc != 5 && argc != 6)
		return (printf("%sError:%s invalid arg count ❌%s\n",
				BRED, CRESET, CBOLD, CRESET), false);
	if (argc == 6)
		must_eat = true;
	else
		must_eat = false;
	if (!ft_check_chars(argv))
		return (false);
	ft_declare_values(argv, data, must_eat);
	return (true);
}
