/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 08:22:35 by kkamashi          #+#    #+#             */
/*   Updated: 2022/04/23 16:17:29 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>

typedef struct	s_philo
{
	int	number_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_must_eat;
}				t_philo;

/*
** LOG.C
*/

void	log_taking_fork(long timestamp_in_ms, int philosopher_number);
void	log_eating(long timestamp_in_ms, int philosopher_number);
void	log_sleeping(long timestamp_in_ms, int philosopher_number);
void	log_thinking(long timestamp_in_ms, int philosopher_number);
void	log_having_died(long timestamp_in_ms, int philosopher_number);

/*
** HANDLE_ERROR.C
*/

void	perror_and_exit(char *str);

/*
** UTILITIES
*/

size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
int		ft_atoi(const char *str);


#endif
