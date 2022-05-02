/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 20:37:05 by kkamashi          #+#    #+#             */
/*   Updated: 2022/05/02 12:56:27 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

void	log_taking_fork(long timestamp_in_ms, int philosopher_number)
{
	printf("%ld %d has taken a fork", timestamp_in_ms, philosopher_number);
}

void	log_eating(long timestamp_in_ms, int philosopher_number)
{
	printf("%ld %d is eating", timestamp_in_ms, philosopher_number);
}

void	log_sleeping(long timestamp_in_ms, int philosopher_number)
{
	printf("%ld %d is sleeping", timestamp_in_ms, philosopher_number);
}

void	log_thinking(long timestamp_in_ms, int philosopher_number)
{
	printf("%ld %d is thinking", timestamp_in_ms, philosopher_number);
}

void	log_having_died(long timestamp_in_ms, int philosopher_number)
{
	printf("%ld %d died", timestamp_in_ms, philosopher_number);
}
