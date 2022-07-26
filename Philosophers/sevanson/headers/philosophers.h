/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevanson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:13:32 by sevanson          #+#    #+#             */
/*   Updated: 2022/10/04 13:07:22 by sevanson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define WRONG_ARGUMENT -1
# define TOO_MANY_ARGUMENTS -2
# define MALLOC_ERROR -3
# define PTHREAD_ERROR -4

struct	s_main;

typedef enum e_action
{
	TAKING_FORK,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
	OVER,
}				t_action;

typedef struct s_philosopher
{
	size_t			position;
	size_t			l_fork;
	size_t			r_fork;
	size_t			meals;
	size_t			eating;
	size_t			final_meal;
	size_t			threshold;
	struct s_main	*instance;
}				t_philosopher;

typedef struct s_main
{
	size_t			amount;
	size_t			timetoeat;
	size_t			timetodie;
	size_t			timetosleep;
	size_t			meals;
	size_t			finished;
	t_philosopher	*philosophers;
	int				*forks;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	*frks_mutexes;
	pthread_mutex_t	die_mutex;
}				t_main;

int		ft_atoi(const char *string, size_t *dst);
void	ft_msg(t_philosopher *philo, size_t timestamp, int action);
int		ft_log(int error);
size_t	get_time(void);
void	*routine(void *vphilo);
int		start(t_main *instance);
int		get_forks(t_philosopher *philo);
int		eat(t_philosopher *philo);
int		release_forks(t_philosopher *philo);
void	ft_usleep(size_t ms);

#endif
