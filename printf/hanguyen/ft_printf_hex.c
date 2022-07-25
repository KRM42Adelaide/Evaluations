/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:15:14 by hanguyen          #+#    #+#             */
/*   Updated: 2022/07/25 12:22:02 by kmachaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hex(size_t num, char *base)
{
	int	count;

	count = 0;
	if (num >= 16)
		count += ft_printf_hex(num / 16, base);
	count += ft_printf_char(base[num % 16]);
	return (count);
}
