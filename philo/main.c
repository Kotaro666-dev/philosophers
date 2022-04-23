/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 08:26:46 by kkamashi          #+#    #+#             */
/*   Updated: 2022/04/23 16:44:06 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initialize(int argc, char **argv, t_philo *philo)
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

int	main(int argc, char **argv)
{
	t_philo philo;

	if (argc != 5 && argc != 6)
		perror_and_exit("Argument count is not correct.");
	initialize(argc, argv, &philo);

	// Debug
	printf("number of philos = %d\n", philo.number_of_philos);
	printf("time to die = %d\n", philo.time_to_die);
	printf("time to eat = %d\n", philo.time_to_eat);
	printf("time to sleep = %d\n", philo.time_to_sleep);
	printf("number of must eat = %d\n", philo.number_of_must_eat);
	return (0);
}
