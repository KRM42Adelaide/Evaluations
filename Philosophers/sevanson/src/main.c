/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevanson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:11:07 by sevanson          #+#    #+#             */
/*   Updated: 2022/10/04 13:13:49 by sevanson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	clear(t_main *instance)
{
	size_t	i;

	i = 0;
	while (i < instance->amount)
	{
		pthread_mutex_destroy(&instance->frks_mutexes[i]);
		i++;
	}
	pthread_mutex_destroy(&instance->write_mutex);
	pthread_mutex_destroy(&instance->die_mutex);
	free(instance->frks_mutexes);
	free(instance->philosophers);
	free(instance->forks);
	return (0);
}

int	initmutex(t_main *instance)
{
	size_t	i;

	instance->frks_mutexes = malloc(sizeof(pthread_mutex_t)
			* instance->amount);
	if (!instance->frks_mutexes)
		return (ft_log(MALLOC_ERROR));
	i = 0;
	while (i < instance->amount)
	{
		pthread_mutex_init(&instance->frks_mutexes[i], NULL);
		i++;
	}
	pthread_mutex_init(&instance->write_mutex, NULL);
	pthread_mutex_init(&instance->die_mutex, NULL);
	return (0);
}

int	init_philo(t_main *instance)
{
	size_t	x;

	instance->philosophers = malloc(sizeof(t_philosopher) * instance->amount);
	instance->forks = malloc(sizeof(int) * instance->amount);
	if (!instance->philosophers || !instance->forks)
		return (ft_log(MALLOC_ERROR));
	x = 0;
	while (x < instance->amount)
	{
		instance->forks[x] = 0;
		instance->philosophers[x].position = x;
		instance->philosophers[x].l_fork = x;
		instance->philosophers[x].r_fork = (x + 1) % instance->amount;
		instance->philosophers[x].meals = 0;
		instance->philosophers[x].eating = 0;
		instance->philosophers[x].instance = instance;
		x++;
	}
	return (0);
}

int	args_init(t_main *instance, int argc, const char **argv)
{
	if (argc < 5 || argc > 6)
		return (ft_log(TOO_MANY_ARGUMENTS));
	if (ft_atoi(argv[1], &instance->amount) || instance->amount == 0
		|| ft_atoi(argv[2], &instance->timetodie) || instance->timetodie == 0
		|| ft_atoi(argv[3], &instance->timetoeat) || instance->timetoeat == 0
		|| ft_atoi(argv[4], &instance->timetosleep)
		|| instance->timetosleep == 0)
		return (ft_log(WRONG_ARGUMENT));
	if (argc == 6 && (ft_atoi(argv[5], &instance->meals)
			|| instance->meals == 0))
		return (ft_log(WRONG_ARGUMENT));
	else if (argc == 5)
		instance->meals = -1;
	instance->finished = 0;
	return (0);
}

int	main(int argc, const char **argv)
{
	t_main	instance;

	if (args_init(&instance, argc, argv)
		|| init_philo(&instance)
		|| initmutex(&instance))
		return (1);
	if (start(&instance))
		return (1);
	pthread_mutex_lock(&instance.die_mutex);
	pthread_mutex_unlock(&instance.die_mutex);
	clear(&instance);
	exit(0);
}
