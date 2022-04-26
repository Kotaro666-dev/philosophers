/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 08:26:46 by kkamashi          #+#    #+#             */
/*   Updated: 2022/04/27 08:17:19 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
