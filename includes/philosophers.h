/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 08:22:35 by kkamashi          #+#    #+#             */
/*   Updated: 2022/04/10 20:44:15 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>

/*
** LOG.C
*/

void	log_taking_fork(long timestamp_in_ms, int philosopher_number);
void	log_eating(long timestamp_in_ms, int philosopher_number);
void	log_sleeping(long timestamp_in_ms, int philosopher_number);
void	log_thinking(long timestamp_in_ms, int philosopher_number);
void	log_having_died(long timestamp_in_ms, int philosopher_number);

#endif
