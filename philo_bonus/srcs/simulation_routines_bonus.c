/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_routines_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becastro <becastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:09:25 by bena              #+#    #+#             */
/*   Updated: 2022/12/10 11:23:26 by becastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_eat(t_philo *philo)
{
	sem_wait(philo->g_data->forks);
	print_philo_status(philo, FORK);
	sem_wait(philo->g_data->forks);
	print_philo_status(philo, FORK);
	ft_usleep(philo->tv->tt_eat);
	philo->last_eat = get_time();
	philo->t_eaten++;
	if (philo->t_eaten == philo->g_data->eat_times)
		sem_post(philo->g_data->eat_sem);
	print_philo_status(philo, EATING);
	sem_post(philo->g_data->forks);
	sem_post(philo->g_data->forks);
}

void	philo_sleep(t_philo *philo)
{
	ft_usleep(philo->tv->tt_sleep);
	print_philo_status(philo, SLEEPING);
}

void	*init_routine(void *philosopher)
{
	t_philo		*philo;
	pthread_t	death_th;
	pthread_t	eaten_th;

	philo = philosopher;
	sem_wait(philo->g_data->init_childs);
	sem_post(philo->g_data->init_childs);
	if (philo->id % 2 == 0)
		ft_usleep(50);
	gettimeofday(&philo->philo_time, NULL);
	pthread_create(&death_th, NULL, death_checker, philo);
	pthread_create(&eaten_th, NULL, times_eaten_checker, philo);
	while (true)
	{
		philo_eat(philo);
		philo_sleep(philo);
		print_philo_status(philo, THINKING);
	}
	exit(EXIT_SUCCESS);
	return (NULL);
}

void	kill_child_process(t_data *data)
{
	t_philo	*aux;

	aux = data->philo_lst;
	while (aux)
	{
		if (aux->id == 1)
			break ;
		aux = aux->next;
	}
	while (aux)
	{
		kill(aux->pid, SIGKILL);
		aux = aux->next;
		if (aux->id == 1)
			break ;
	}
}
