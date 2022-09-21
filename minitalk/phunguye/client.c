/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:43:12 by phunguye          #+#    #+#             */
/*   Updated: 2022/09/21 12:22:05 by kmachaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	if (!str)
		return (0);
	i = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + ((str[i++] - '0'));
	return (res * sign);
}

//the character is expressed in bits and sent in 1=SIGUSR1 and 0=SIGUSR2's
//>>shifts the bits i to the right, reads bits from the left
//usleep just delays for 100 microseconds
void	send_char(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(25);
		i--;
	}
}

//startup ./client arg[pid] arg[MSG]
int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_printf("Bad arguments | ./client [pid] ['message']");
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid == 0)
	{
		ft_printf("Error - Bad PID.\n");
		return (0);
	}
	while (av[2][i])
		send_char(av[2][i++], pid);
	return (1);
}
