/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 08:27:30 by kkamashi          #+#    #+#             */
/*   Updated: 2022/05/03 17:19:01 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

void	close_forks(t_philo *philo)
{
	if (sem_close(philo->forks) == -1)
	{
		perror_and_exit_with_errno("sem_close");
	}
	if (sem_unlink(SEMAPHORE_FORKS_NAME) == -1)
	{
		perror_and_exit_with_errno("sem_unlink");
	}
}

void	close_waiter(t_philo *philo)
{
	if (sem_close(philo->waiter) == -1)
	{
		perror_and_exit_with_errno("sem_close");
	}
	if (sem_unlink(SEMAPHORE_WAITER_NAME) == -1)
	{
		perror_and_exit_with_errno("sem_unlink");
	}
}

void	clean_up(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->config.number_of_philos)
	{
		// TOOD: philosophers の中で確保したものがあれば、開放する
		i++;
	}
	close_forks(philo);
	close_waiter(philo);
	free(philo->philosophers);
	philo->philosophers = NULL;
}
