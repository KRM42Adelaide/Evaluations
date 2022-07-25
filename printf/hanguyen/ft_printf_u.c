/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:45:01 by hanguyen          #+#    #+#             */
/*   Updated: 2022/07/25 12:23:47 by kmachaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_u(unsigned int num)
{
	int	count;

	count = 0;
	if (num >= 10)
		count += ft_printf_number(num / 10);
	count += ft_printf_char(num % 10 + '0');
	return (count);
}
