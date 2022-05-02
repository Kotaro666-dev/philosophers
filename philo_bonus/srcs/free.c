/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 08:27:30 by kkamashi          #+#    #+#             */
/*   Updated: 2022/05/02 13:00:02 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

void	close_forks(t_philo *philo)
{
	if (sem_close(philo->forks) == -1)
	{
		perror("sem_close");
		exit(errno);
	}
	if (sem_unlink(SEMAPHORE_FORKS_NAME) == -1)
		{
			perror("sem_unlink");
			exit(errno);
		}
}
