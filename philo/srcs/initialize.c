/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 08:17:04 by kkamashi          #+#    #+#             */
/*   Updated: 2022/04/27 08:33:52 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	initialize_forks(t_philo *philo)
{
	int i;

	i = 0;
	philo->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) *
												philo->number_of_philos);
	if (!philo->forks)
	{
		perror("malloc");
		exit(errno);
	}
	while (i < philo->number_of_philos)
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

static void	parse_args(int argc, char **argv, t_philo *philo)
{
	philo->number_of_philos = ft_atoi(argv[1]);
	if (philo->number_of_philos < 2)
		perror_and_exit("Number of philosophers must be more than 2.");
	philo->time_to_die = ft_atoi(argv[2]);
	if (philo->time_to_die < 0)
		perror_and_exit("Time to die must be positive number.");
	philo->time_to_eat = ft_atoi(argv[3]);
	if (philo->time_to_eat < 0)
		perror_and_exit("Time to eat must be positive number.");
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (philo->time_to_sleep < 0)
		perror_and_exit("Time to sleep must be positive number.");
	if (argc == 6)
	{
		philo->number_of_must_eat = ft_atoi(argv[5]);
		if (philo->number_of_must_eat <= 0)
			perror_and_exit("Number of must eat must be more than 0.");
	}
	else
	{
		philo->number_of_must_eat = 0;
	}
}

void	initialize(int argc, char **argv, t_philo *philo)
{
	parse_args(argc, argv, philo);
	initialize_forks(philo);
}
