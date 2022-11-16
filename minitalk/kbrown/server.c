/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrown <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:29:12 by kbrown            #+#    #+#             */
/*   Updated: 2022/10/31 16:09:53 by kmachaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// binary to ascii
void	convert(int signal)
{
	g_msg.c += ((signal & 1) << g_msg.i);
	if (++g_msg.i == 7)
	{
		write(1, &g_msg.c, 1);
		if (!g_msg.c)
			write(1, "\n", 1);
		g_msg.c = 0;
		g_msg.i = 0;
	}
}

int	main(void)
{
	g_msg.i = 0;
	g_msg.c = 0;
	ft_printf("%s\n", "server is operational");
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, convert);
		signal(SIGUSR1, convert);
		pause();
	}
	return (0);
}
