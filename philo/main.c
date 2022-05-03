/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 08:26:46 by kkamashi          #+#    #+#             */
/*   Updated: 2022/05/03 12:13:35 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** int pthread_create(pthread_t * thread, pthread_attr_t * attr,
** 		void * (*start_routine)(void *), void * arg);
*/

static void	start_philosophers(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->config.number_of_philos)
	{
		if (pthread_create(&(philo->philosophers[i].pthread_person), NULL,
				start_dining, &(philo->philosophers[i])) != 0)
		{
			// 動的メモリの開放
			perror_and_exit("pthread_create");
		}
		if (pthread_create(&(philo->philosophers[i].pthread_monitor), NULL,
				start_monitoring, &(philo->philosophers[i])) != 0)
		{
			// 動的メモリの開放
			perror_and_exit("pthread_create");
		}
		i++;
	}
	i = 0;
	while (i < philo->config.number_of_philos)
	{
		pthread_join(philo->philosophers[i].pthread_person, NULL);
		pthread_join(philo->philosophers[i].pthread_monitor, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc != BASIC_ARGC && argc != ARGC_WITH_OPTION)
	{
		perror_and_exit("Argument count is not correct.");
	}
	initialize(argc, argv, &philo);
	start_philosophers(&philo);
	return (0);
}
