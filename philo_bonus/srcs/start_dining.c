/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dining.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:50:43 by kkamashi          #+#    #+#             */
/*   Updated: 2022/05/03 16:57:06 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

static void	take_fork(t_philosopher *philosopher)
{
	sem_wait(philosopher->forks);
	log_taking_fork(philosopher->id + 1);
}

static int	take_fork_on_left_side(t_philosopher *philosopher)
{
	sem_wait(philosopher->waiter);
	if (*(philosopher->forks) < 2)
	{
		sem_post(philosopher->waiter);
		// TODO:　少し usleep してもいいかも
		take_fork_on_left_side(philosopher);
	}
	take_fork(philosopher);
	sem_post(philosopher->waiter);
}

static int	take_fork_on_right_side(t_philosopher *philosopher)
{
	sem_wait(philosopher->waiter);
	if (*(philosopher->forks) == 0)
	{
		sem_post(philosopher->waiter);
		// TODO:　少し usleep してもいいかも
		take_fork_on_right_side(philosopher);
	}
	take_fork(philosopher);
	sem_post(philosopher->waiter);
}

static void	put_forks_back_on_table(t_philosopher *philosopher)
{
	sem_post(philosopher->forks);
	sem_post(philosopher->forks);
	printf("Put forks back on table.\n");
}

/*
** 哲学者は食べ終わったら、寝始める行動は必要不可欠
** 起床してまだ食べる必要があれば、まず考え始める必要がある
*/

void	*start_dining(void *void_philosopher)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)void_philosopher;
	while (!(philosopher->have_died))
	{
		take_fork_on_left_side(philosopher);
		take_fork_on_right_side(philosopher);
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
