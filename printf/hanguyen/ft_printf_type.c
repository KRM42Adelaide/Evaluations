/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:21:52 by hanguyen          #+#    #+#             */
/*   Updated: 2022/07/25 12:23:34 by kmachaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(const char c, va_list args)
{
	if (c == 'c')
		return (ft_printf_char(va_arg(args, int)));
	if (c == 's')
		return (ft_printf_str(va_arg(args, char *)));
	if (c == 'i' || c == 'd')
		return (ft_printf_number(va_arg(args, int)));
	if (c == 'u')
		return (ft_printf_u(va_arg(args, int)));
	if (c == 'x')
		return (ft_printf_hex(va_arg(args, int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_printf_hex(va_arg(args, int), "0123456789ABCDEF"));
	if (c == 'p')
		return (ft_printf_ptr(va_arg(args, void *)));
	if (c == '%')
		return (ft_printf_char('%'));
	else
		return (0);
}
