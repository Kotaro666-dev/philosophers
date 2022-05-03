/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:37:05 by kkamashi          #+#    #+#             */
/*   Updated: 2022/05/03 13:25:33 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

void	log_taking_fork(int philosopher_number)
{
	long	timestamp;

	timestamp = get_current_timestamp();
	printf("%ld %d has taken a fork\n", timestamp, philosopher_number);
}

void	log_eating(int philosopher_number)
{
	long	timestamp;

	timestamp = get_current_timestamp();
	printf("%ld %d is eating\n", timestamp, philosopher_number);
}

void	log_sleeping(int philosopher_number)
{
	long	timestamp;

	timestamp = get_current_timestamp();
	printf("%ld %d is sleeping\n", timestamp, philosopher_number);
}

void	log_thinking(int philosopher_number)
{
	long	timestamp;

	timestamp = get_current_timestamp();
	printf("%ld %d is thinking\n", timestamp, philosopher_number);
}

void	log_having_died(int philosopher_number)
{
	long	timestamp;

	timestamp = get_current_timestamp();
	printf("%ld %d died\n", timestamp, philosopher_number);
}
