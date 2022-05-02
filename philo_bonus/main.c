/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 08:26:46 by kkamashi          #+#    #+#             */
/*   Updated: 2022/05/02 11:44:46 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc != BASIC_ARGC && argc != ARGC_WITH_OPTION)
		perror_and_exit("Argument count is not correct.");
	initialize(argc, argv, &philo);
	return (0);
}
