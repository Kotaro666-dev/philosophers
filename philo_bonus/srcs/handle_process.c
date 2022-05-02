/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:26:05 by kkamashi          #+#    #+#             */
/*   Updated: 2022/05/02 14:33:41 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

static void	start_phlosopher_process(int index, t_philo *philo)
{
	(void)philo;
	printf("CREATE: Philosopher %d process.\n", index);
	// TODO: 哲学者とモニターのスレッドを作る
	usleep(1000000);
	exit(EXIT_SUCCESS);
}

static void	kill_all_philosophers_processes(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->config.number_of_philos)
	{
		if (kill(philo->philosophers[i].pid, SIGTERM) == -1)
		{
			close_forks(philo);
			perror_and_exit_with_errno("kill");
		}
	}
}

void	wait_all_philosophers_processes(t_philo *philo)
{
	int	i;
	int	wstatus;

	i = 0;
	wstatus = 0;
	while (i < philo->config.number_of_philos)
	{
		if (waitpid(-1, &wstatus, 0) == -1)
		{
			close_forks(philo);
			perror_and_exit_with_errno("waitpid");
		}
		if (wstatus != EXIT_SUCCESS)
		{
			kill_all_philosophers_processes(philo);
		}
		printf("FINISH: Philosopher %d process.\n", philo->philosophers[i].pid);
		i++;
	}
}

void	fork_philosophers_processes(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->config.number_of_philos)
	{
		philo->philosophers[i].pid = fork();
		if (philo->philosophers[i].pid == -1)
		{
			close_forks(philo);
			perror_and_exit_with_errno("fork");
		}
		else if (philo->philosophers[i].pid == 0)
		{
			start_phlosopher_process(i, philo);
		}
		i++;
	}
}
