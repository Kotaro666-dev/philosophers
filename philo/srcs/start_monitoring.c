/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_monitoring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:52:36 by kkamashi          #+#    #+#             */
/*   Updated: 2022/04/29 10:52:50 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*start_monitoring(void *void_philosopher)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)void_philosopher;
	// printf("%d is monitoring.\n", philosopher->id + 1);
	// TODO: 哲学者が死んだかどうかを判定
	// 死んだら、ログを出力する
	return (NULL);
}
