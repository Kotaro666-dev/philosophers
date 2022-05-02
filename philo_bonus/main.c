/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 08:26:46 by kkamashi          #+#    #+#             */
/*   Updated: 2022/05/02 14:38:58 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

static void	clean_up(t_philo *philo)
{
	// TODO: 動的メモリの開放
	close_forks(philo);
}

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
