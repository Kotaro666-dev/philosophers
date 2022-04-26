/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 08:27:30 by kkamashi          #+#    #+#             */
/*   Updated: 2022/04/27 08:32:57 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_forks(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philos)
	{
		if (pthread_mutex_destroy(&philo->forks[i]) != 0)
		{
			perror("pthread_mutex_destroy");
			exit(errno);
		}
	}
}
