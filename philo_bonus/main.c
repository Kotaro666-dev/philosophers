/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 08:26:46 by kkamashi          #+#    #+#             */
/*   Updated: 2022/05/03 12:35:20 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

void	start_philosophers(t_philo *philo)
{
	fork_philosophers_processes(philo);
	wait_all_philosophers_processes(philo);
	clean_up(philo);
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
