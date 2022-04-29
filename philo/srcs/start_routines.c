/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_routines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:48:24 by kkamashi          #+#    #+#             */
/*   Updated: 2022/04/29 13:47:47 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	pthread_mutex_lock(&(philosopher->is_eating_mutex));
	if (philosopher->have_died)
	{
		pthread_mutex_unlock(&(philosopher->is_eating_mutex));
		return ;
	}
	log_eating(philosopher->id + 1);
	philosopher->number_of_eaten++;
	philosopher->last_meal_time = get_current_timestamp();
	pthread_mutex_unlock(&(philosopher->is_eating_mutex));
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
