/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 08:17:04 by kkamashi          #+#    #+#             */
/*   Updated: 2022/05/03 12:34:49 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

static void	parse_args(int argc, char **argv, t_philo *philo)
{
	philo->config.number_of_philos = ft_atoi(argv[1]);
	if (philo->config.number_of_philos < 2)
		perror_and_exit("Number of philosophers must be more than 2.");
	philo->config.time_to_die = ft_atoi(argv[2]);
	if (philo->config.time_to_die < 0)
		perror_and_exit("Time to die must be positive number.");
	philo->config.time_to_eat = ft_atoi(argv[3]);
	if (philo->config.time_to_eat < 0)
		perror_and_exit("Time to eat must be positive number.");
	philo->config.time_to_sleep = ft_atoi(argv[4]);
	if (philo->config.time_to_sleep < 0)
		perror_and_exit("Time to sleep must be positive number.");
	if (argc == 6)
	{
		philo->config.number_of_must_eat = ft_atoi(argv[5]);
		if (philo->config.number_of_must_eat <= 0)
			perror_and_exit("Number of must eat must be more than 0.");
	}
	else
	{
		philo->config.number_of_must_eat = 0;
	}
}

static void	initialize_philosopher(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->config.number_of_philos)
	{
		philo->philosophers[i].pid = 0;
		philo->philosophers[i].id = i;
		philo->philosophers[i].number_of_eaten = 0;
		philo->philosophers[i].last_meal_time = get_current_timestamp();
		philo->philosophers[i].have_eaten_all = FALSE;
		philo->philosophers[i].have_died = FALSE;
		philo->philosophers[i].config = &(philo->config);
		if (pthread_mutex_init(&(philo->philosophers[i].is_eating_mutex), NULL) != 0)
		{
			clean_up(philo);
			perror_and_exit("pthread_mutex_init");
		}
		i++;
	}
}

static void	initialize_philosophers(t_philo *philo)
{
	philo->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher)
		* philo->config.number_of_philos);
	if (!philo->philosophers)
	{
		perror_and_exit("malloc");
	}
	initialize_philosopher(philo);
}

void	initialize_forks(t_philo *philo)
{
	philo->forks = sem_open(SEMAPHORE_FORKS_NAME, O_CREAT | O_EXCL, 0x777,
		philo->config.number_of_philos);
	if (philo->forks == SEM_FAILED)
	{
		if (sem_unlink(SEMAPHORE_FORKS_NAME) == -1)
		{
			perror_and_exit_with_errno("sem_unlink");
		}
		perror_and_exit_with_errno("sem_open");
	}
}


void	initialize(int argc, char **argv, t_philo *philo)
{
	parse_args(argc, argv, philo);
	initialize_forks(philo);
	initialize_philosophers(philo);
}
