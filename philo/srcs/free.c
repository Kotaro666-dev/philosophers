/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 08:27:30 by kkamashi          #+#    #+#             */
/*   Updated: 2022/05/03 12:27:18 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_forks(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->config.number_of_philos)
	{
		if (pthread_mutex_destroy(&philo->forks[i]) != 0)
		{
			perror_and_exit("pthread_mutex_destroy");
		}
	}
}

void	clean_up(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->config.number_of_philos)
	{
		if (pthread_mutex_destroy(&philo->forks[i]) != 0)
		{
			perror_and_exit("pthread_mutex_destroy");
		}
		if (pthread_mutex_destroy(&philo->philosophers[i].is_eating_mutex) != 0)
		{
			perror_and_exit("pthread_mutex_destroy");
		}
		i++;
	}
	free(philo->philosophers);
	philo->philosophers = NULL;
}
