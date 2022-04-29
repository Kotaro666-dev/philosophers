/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 08:22:35 by kkamashi          #+#    #+#             */
/*   Updated: 2022/04/29 13:21:38 by kkamashi         ###   ########.fr       */
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

typedef struct s_config
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_must_eat;
}				t_config;

typedef struct s_philosopher
{
	int				id;
	int				number_of_eaten;
	int				last_meal_time;
	int				have_eaten_all;
	int				have_died;
	t_config		*config;
	pthread_t		pthread_person;
	pthread_t		pthread_monitor;
	pthread_mutex_t	*fork_on_left_hand;
	pthread_mutex_t	*fork_on_right_hand;
	pthread_mutex_t	is_eating_mutex;
}				t_philosopher;

typedef struct s_philo
{
	t_config		config;
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks;
}				t_philo;

/*
** START_DINING.C
*/

void	*start_dining(void *void_philosopher);

/*
** START_MONITORING.C
*/

void	*start_monitoring(void *void_philosopher);

/*
** START_ROUTINES.C
*/

void	wait_til_next_action(int milliseconds);
void	start_eating(t_philosopher *philosopher);
void	start_thinking(t_philosopher *philosopher);
void	start_sleeping(t_philosopher *philosopher);

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
