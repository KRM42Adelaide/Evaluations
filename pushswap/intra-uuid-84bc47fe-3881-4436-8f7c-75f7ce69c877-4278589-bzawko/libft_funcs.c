/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:02:40 by bzawko            #+#    #+#             */
/*   Updated: 2022/06/12 15:02:42 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *nptr)
{
	long int	ret;
	int			negative;

	ret = 0;
	negative = 1;
	if (*nptr == '-')
	{
		if (*nptr == '-')
			negative = -1;
		++nptr;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		ret *= 10;
		ret += (*nptr - 48);
		++nptr;
	}
	if (ret < INT_MIN || ret > INT_MAX || \
			(*nptr < '0' && *nptr != '\0') || (*nptr > '9' && *nptr != '\0'))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	return (ret * negative);
}
