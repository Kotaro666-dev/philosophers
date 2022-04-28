/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 08:50:26 by kkamashi          #+#    #+#             */
/*   Updated: 2022/04/28 21:42:42 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** usleep - マイクロ秒単位で実行を延期する
** microseconds = milliseconds * 1000
*/

void	wait_til_next_action(int milliseconds)
{
	usleep(milliseconds * 1000);
}

void	start_eating(t_philosopher *philosopher)
{
	log_eating(philosopher->id + 1);
	wait_til_next_action(philosopher->time_to_eat);
}

void	start_thinking(t_philosopher *philosopher)
{
	log_thinking(philosopher->id + 1);
	wait_til_next_action(TIME_TO_THINK);
}

void	start_sleeping(t_philosopher *philosopher)
{
	log_sleeping(philosopher->id + 1);
	wait_til_next_action(philosopher->time_to_sleep);
}

void	*start_dining(void *void_philosopher)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)void_philosopher;
	if (philosopher->id % 2 != 0)
	{
		wait_til_next_action(TIME_TO_THINK);
	}
	while (TRUE)
	{
		// TODO: 一連の食事を行う
		// 1. 右のフォークを取る
		// 2. 左のフォークを取る
		// 3. 食べる
		start_eating(philosopher);
		philosopher->number_of_eaten++;
		// 4. 寝る
		start_sleeping(philosopher);
		// 5. 考える
		start_thinking(philosopher);
		if (philosopher->number_of_eaten == philosopher->number_of_must_eat)
		{
			printf("%d has eaten all.\n", philosopher->id + 1);
			break;
		}
	}
	return (NULL);
}

void	*start_monitoring(void *void_philosopher)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)void_philosopher;
	printf("%d is monitoring.\n", philosopher->id + 1);
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
	while (i < philo->number_of_philos)
	{
		pthread_join(philo->philosophers[i].pthread_person, NULL);
		pthread_join(philo->philosophers[i].pthread_monitor, NULL);
		i++;
	}
}
