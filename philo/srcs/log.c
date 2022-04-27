/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:37:05 by kkamashi          #+#    #+#             */
/*   Updated: 2022/04/27 09:17:41 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	log_taking_fork(int philosopher_number)
{
	long	timestamp;

	timestamp = get_current_timestamp();
	printf("%ld %d has taken a fork", timestamp, philosopher_number);
}

void	log_eating(int philosopher_number)
{
	long	timestamp;

	timestamp = get_current_timestamp();
	printf("%ld %d is eating", timestamp, philosopher_number);
}

void	log_sleeping(int philosopher_number)
{
	long	timestamp;

	timestamp = get_current_timestamp();
	printf("%ld %d is sleeping", timestamp, philosopher_number);
}

void	log_thinking(int philosopher_number)
{
	long	timestamp;

	timestamp = get_current_timestamp();
	printf("%ld %d is thinking", timestamp, philosopher_number);
}

void	log_having_died(int philosopher_number)
{
	long	timestamp;

	timestamp = get_current_timestamp();
	printf("%ld %d died", timestamp, philosopher_number);
}
