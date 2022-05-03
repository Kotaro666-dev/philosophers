/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dining.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:50:43 by kkamashi          #+#    #+#             */
/*   Updated: 2022/05/03 13:39:08 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

static void	take_fork(t_philosopher *philosopher)
{
	// ウェイターにフォークを取れるか問い合わせる
	// フォークが残り2本以上の場合、問答無用で許可する
	// フォークが残り1本の場合、リクエストした哲学者の保持するフォークが1本の場合、許可する
	// フォークが残り1本の場合、リクエストした哲学者の保持するフォークが0本の場合、許可しない
	// フォークが残り0本の場合、許可しない
	log_taking_fork(philosopher->id + 1);
}

static void	put_forks_back_on_table(t_philosopher *philosopher)
{
	// sem_post();
	// sem_post();
	(void)philosopher;
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
		take_fork(philosopher);
		take_fork(philosopher);
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
