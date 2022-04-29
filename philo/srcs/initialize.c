/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 08:17:04 by kkamashi          #+#    #+#             */
/*   Updated: 2022/04/29 11:08:00 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		philo->philosophers[i].id = i;
		philo->philosophers[i].time_to_die = philo->config.time_to_die;
		philo->philosophers[i].time_to_eat = philo->config.time_to_eat;
		philo->philosophers[i].time_to_sleep = philo->config.time_to_sleep;
		philo->philosophers[i].number_of_eaten = 0;
		philo->philosophers[i].number_of_must_eat
			= philo->config.number_of_must_eat;
		philo->philosophers[i].have_died = FALSE;
		philo->philosophers[i].fork_on_right_hand = &(philo->forks[i]);
		if (i == philo->config.number_of_philos - 1)
		{
			philo->philosophers[i].fork_on_left_hand = &(philo->forks[0]);
		}
		else
		{
			philo->philosophers[i].fork_on_left_hand = &(philo->forks[i + 1]);
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
		perror("malloc");
		exit(errno);
	}
	initialize_philosopher(philo);
}

static void	initialize_forks(t_philo *philo)
{
	int	i;

	i = 0;
	philo->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* philo->config.number_of_philos);
	if (!philo->forks)
	{
		perror("malloc");
		exit(errno);
	}
	while (i < philo->config.number_of_philos)
	{
		if (pthread_mutex_init(&philo->forks[i], NULL) != 0)
		{
			free_forks(philo);
			perror("pthread_mutex_init");
			exit(errno);
		}
		i++;
	}
}

void	initialize(int argc, char **argv, t_philo *philo)
{
	parse_args(argc, argv, philo);
	initialize_forks(philo);
	initialize_philosophers(philo);
}
