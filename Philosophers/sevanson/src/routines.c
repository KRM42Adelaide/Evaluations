/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevanson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:19:17 by sevanson          #+#    #+#             */
/*   Updated: 2022/09/29 19:19:31 by sevanson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *vphilo)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)vphilo;
	philo->final_meal = get_time();
	philo->threshold = philo->final_meal + philo->instance->timetodie;
	while (1)
	{
		if (eat(philo) || get_forks(philo) || release_forks(philo))
			break ;
	}
	return (NULL);
}
