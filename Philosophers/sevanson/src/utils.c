/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevanson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:20:52 by sevanson          #+#    #+#             */
/*   Updated: 2022/09/29 19:20:58 by sevanson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *string, size_t *dst)
{
	int	i;

	i = 0;
	if (string[i] == '\0')
		return (1);
	*dst = 0;
	while (string[i] && string[i] >= '0' && string[i] <= '9')
	{
		*dst = *dst * 10 + (string[i] - '0');
		i++;
	}
	if (string[i] != '\0')
		return (1);
	return (0);
}

size_t	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(size_t ms)
{
	size_t	end;

	end = get_time() + ms;
	while (get_time() < end)
		usleep(ms / 1000);
}
