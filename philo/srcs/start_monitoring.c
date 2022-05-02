/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:52:36 by kkamashi          #+#    #+#             */
/*   Updated: 2022/05/02 11:48:42 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*start_monitoring(void *void_philosopher)
{
	t_philosopher	*philosopher;
	int	current_time;

	philosopher = (t_philosopher *)void_philosopher;
	while (!(philosopher->have_eaten_all))
	{
		pthread_mutex_lock(&(philosopher->is_eating_mutex));
		current_time = get_current_timestamp();
		if (current_time - philosopher->last_meal_time >= philosopher->config->time_to_die)
		{
			log_having_died(philosopher->id + 1);
			philosopher->have_died = TRUE;
		}
		pthread_mutex_unlock(&(philosopher->is_eating_mutex));
		if (philosopher->have_died)
		{
			break ;
		}
		wait_til_next_action(TIME_TO_DO_NEXT_MONITORING);
	}
	return (NULL);
}
