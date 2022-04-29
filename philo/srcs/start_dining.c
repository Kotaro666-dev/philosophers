/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dining.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:50:43 by kkamashi          #+#    #+#             */
/*   Updated: 2022/04/29 12:04:03 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	take_fork_on_right_side(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->fork_on_right_hand);
	log_taking_fork(philosopher->id + 1);
}

static void	take_fork_on_left_side(t_philosopher *philosopher)
{
	pthread_mutex_lock(philosopher->fork_on_left_hand);
	log_taking_fork(philosopher->id + 1);
}

static void	put_forks_back_on_table(t_philosopher *philosopher)
{
	pthread_mutex_unlock(philosopher->fork_on_right_hand);
	pthread_mutex_unlock(philosopher->fork_on_left_hand);
}

static void	force_even_number_philosopher_to_wait(t_philosopher *philosopher)
{
	int	is_even_number_philosopher;

	is_even_number_philosopher = ((philosopher->id + 1) % 2 == 0);
	if (is_even_number_philosopher)
	{
		wait_til_next_action(TIME_TO_WAIT_BEFORE_DINING);
	}
}

/*
** 哲学者は食べ終わったら、寝始める行動は必要不可欠
** 起床してまだ食べる必要があれば、まず考え始める必要がある
*/

void	*start_dining(void *void_philosopher)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)void_philosopher;
	force_even_number_philosopher_to_wait(philosopher);
	while (!(philosopher->have_died))
	{
		take_fork_on_right_side(philosopher);
		take_fork_on_left_side(philosopher);
		start_eating(philosopher);
		put_forks_back_on_table(philosopher);
		start_sleeping(philosopher);
		if (philosopher->number_of_eaten == philosopher->config->number_of_must_eat)
		{
			philosopher->have_eaten_all = TRUE;
			break;
		}
		start_thinking(philosopher);
	}
	return (NULL);
}
