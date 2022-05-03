/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:48:24 by kkamashi          #+#    #+#             */
/*   Updated: 2022/05/03 13:40:47 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

/*
** usleep - マイクロ秒単位で実行を延期する
** microseconds = milliseconds * 1000
*/

void	wait_til_next_action(int milliseconds)
{
	usleep(milliseconds * 1000);
}

void	start_eating(t_philosopher *philosopher)
{
	sem_wait(philosopher->is_eating_semaphore);
	if (philosopher->have_died)
	{
		sem_post(philosopher->is_eating_semaphore);
		return ;
	}
	log_eating(philosopher->id + 1);
	philosopher->last_meal_time = get_current_timestamp();
	philosopher->number_of_eaten++;
	sem_post(philosopher->is_eating_semaphore);
	wait_til_next_action(philosopher->config->time_to_eat);
}

void	start_sleeping(t_philosopher *philosopher)
{
	if (philosopher->have_died)
	{
		return ;
	}
	log_sleeping(philosopher->id + 1);
	wait_til_next_action(philosopher->config->time_to_sleep);
}

void	start_thinking(t_philosopher *philosopher)
{
	if (philosopher->have_died)
	{
		return ;
	}
	log_thinking(philosopher->id + 1);
	wait_til_next_action(TIME_TO_THINK);
}
