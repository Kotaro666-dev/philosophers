/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 08:50:26 by kkamashi          #+#    #+#             */
/*   Updated: 2022/04/28 20:18:48 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_til_next_action(int milliseconds)
{
	usleep(milliseconds);
}

void	start_eating(int philosopher, t_philo *philo)
{
	log_eating(philosopher);
	wait_til_next_action(philo->time_to_eat);
}


void	start_thinking(int philosopher)
{
	log_thinking(philosopher);
	wait_til_next_action(TIME_TO_THINK);
}

void	start_sleeping(int philosopher, t_philo *philo)
{
	log_sleeping(philosopher);
	wait_til_next_action(philo->time_to_sleep);
}

void	*start_dining(void *index)
{
	int	philosopher;

	philosopher = *((int*)index);
	// TODO: 一連の食事を行う
	printf("%d is dining.\n", philosopher + 1);
	return (NULL);

}

void	*start_monitoring(void *index)
{
	int	philosopher;

	philosopher = *((int*)index);
	printf("%d is monitoring.\n", philosopher + 1);
	// TODO: 哲学者が死んだかどうかを判定
	// 死んだら、ログを出力する
	return (NULL);
}

/*
** int pthread_create(pthread_t * thread, pthread_attr_t * attr,
** 		void * (*start_routine)(void *), void * arg);
*/

void	start_philosophers(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philos)
	{
		if (pthread_create(&philo->philosophers[i], NULL, start_dining, &i) != 0)
		{
			// 動的メモリの開放
			perror_and_exit("pthread_create");
		}
		if (pthread_create(&philo->monitors[i], NULL, start_monitoring, &i) != 0)
		{
			// 動的メモリの開放
			perror_and_exit("pthread_create");
		}
		i++;
	}
	i = 0;
	while (i < philo->number_of_philos)
	{
		pthread_join(philo->philosophers[i], NULL);
		// pthread_join(philo->monitors[i], NULL);
		i++;
	}
}
