/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_timestamp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:08:11 by kkamashi          #+#    #+#             */
/*   Updated: 2022/05/02 12:56:46 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

long	get_current_timestamp()
{
	struct timeval	time;
	long	milliseconds;

	if (gettimeofday(&time, NULL) == -1)
	{
		// TODO: 動的メモリの開放
		perror("gettimeofday");
		exit(errno);
	}
	milliseconds = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (milliseconds);
}
