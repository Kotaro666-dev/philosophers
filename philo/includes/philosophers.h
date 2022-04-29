/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 08:22:35 by kkamashi          #+#    #+#             */
/*   Updated: 2022/04/29 09:46:47 by kkamashi         ###   ########.fr       */
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
# include <errno.h>
# include <sys/time.h>
# include "constants.h"

typedef struct s_philosopher
{
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_eaten;
	int				number_of_must_eat;
	int				have_died;
	pthread_t		pthread_person;
	pthread_t		pthread_monitor;
	pthread_mutex_t	*fork_on_left_hand;
	pthread_mutex_t	*fork_on_right_hand;
}				t_philosopher;

typedef struct s_philo
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_must_eat;
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks;
}				t_philo;

/*
** START_PHILOSOPHERS.C
*/

void	start_philosophers(t_philo *philo);

/*
** INITIALIZE.C
*/

void	initialize(int argc, char **argv, t_philo *philo);

/*
** LOG.C
*/

void	log_taking_fork(int philosopher_number);
void	log_eating(int philosopher_number);
void	log_sleeping(int philosopher_number);
void	log_thinking(int philosopher_number);
void	log_having_died(int philosopher_number);

/*
** HANDLE_ERROR.C
*/

void	perror_and_exit(char *str);

/*
** FREE.C
*/

void	free_forks(t_philo *philo);

/*
** UTILITIES
*/

size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
int		ft_atoi(const char *str);
long	get_current_timestamp();

#endif
