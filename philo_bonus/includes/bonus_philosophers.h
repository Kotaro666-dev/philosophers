/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philosophers.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamashi <kkamashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 08:22:35 by kkamashi          #+#    #+#             */
/*   Updated: 2022/05/03 13:38:44 by kkamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PHILOSOPHERS_H
# define BONUS_PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <limits.h>
# include <errno.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <sys/types.h>
# include <signal.h>
# include "bonus_constants.h"

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
	pid_t			pid;
	int				id;
	int				number_of_eaten;
	int				last_meal_time;
	int				have_eaten_all;
	int				have_died;
	t_config		*config;
	sem_t			*is_eating_semaphore;
	pthread_t		pthread_person;
	pthread_t		pthread_monitor;
}				t_philosopher;

typedef struct s_philo
{
	t_config		config;
	t_philosopher	*philosophers;
	sem_t			*forks;
}				t_philo;

/*
** INITIALIZE.C
*/

void	initialize(int argc, char **argv, t_philo *philo);

/*
** HANDLE_PROCESS.C
*/

void	wait_all_philosophers_processes(t_philo *philo);
void	fork_philosophers_processes(t_philo *philo);

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
** HANDLE_ERROR.C
*/

void	perror_and_exit(char *str);
void	perror_and_exit_with_errno(char *str);

/*
** FREE.C
*/

void	close_forks(t_philo *philo);
void	clean_up(t_philo *philo);

/*
** LOG.C
*/

void	log_taking_fork(int philosopher_number);
void	log_eating(int philosopher_number);
void	log_sleeping(int philosopher_number);
void	log_thinking(int philosopher_number);
void	log_having_died(int philosopher_number);

/*
** UTILITIES
*/

size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
int		ft_atoi(const char *str);
long	get_current_timestamp();

#endif
