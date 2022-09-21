/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:17:59 by phunguye          #+#    #+#             */
/*   Updated: 2022/09/21 12:21:49 by kmachaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	handler(int sig_num)
{
	static int	location;
	static int	byte;

	if (sig_num == SIGUSR1)
		byte += 1 << (7 - location);
	location++;
	if (location == 8)
	{
		ft_putchar(byte);
		location = 0;
		byte = 0;
	}
}

//int signal () (int signum, void (*func)(int))
//pause() suspends program execution until a signal arrives 
int	main(int ac, char **av)
{
	pid_t	pid;

	(void)av;
	if (ac == 1)
	{
		pid = getpid();
		ft_printf("PID: %d\n----------\nMSG:\n", pid);
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		while (1)
			pause();
	}
	if (ac != 1)
		printf("Error! Did you mean: ./server.out?\n");
	return (0);
}
