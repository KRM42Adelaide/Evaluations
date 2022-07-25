/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:26:45 by hanguyen          #+#    #+#             */
/*   Updated: 2022/07/25 12:22:20 by kmachaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_number(int num)
{
	unsigned int	n;
	int				count;

	count = 0;
	if (num < 0)
	{
		count += ft_printf_char('-');
		n = (unsigned int)(num * -1);
	}
	else
		n = (unsigned int)num;
	if (n >= 10)
		count += ft_printf_number(n / 10);
	count += ft_printf_char(n % 10 + '0');
	return (count);
}
