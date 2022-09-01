/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 08:09:42 by becastro          #+#    #+#             */
/*   Updated: 2022/09/01 10:14:06 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_declare_values(char **argv, t_data *data)
{

}

bool	ft_check_args(int argc, char **argv, t_data *data)
{
	u_int16_t	i;
	u_int16_t	j;

	(void)data;
	i = 0;
	j = -1;
	if (argc != 5 && argc != 6)
	{
		printf("Error, invalid arg count ❌\n");
		return (false);
	}
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("Error, arg number %d has invalid characters ❌\n", i);
				return (false);
			}
		}
	}
	ft_declare_values(argv, data);
	return (true);
}
