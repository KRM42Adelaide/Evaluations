/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanguyen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:06:37 by hanguyen          #+#    #+#             */
/*   Updated: 2022/07/25 12:22:35 by kmachaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_ptr(void *ptr)
{
	int	count;

	count = 0;
	ft_putstr_fd("0x", 1);
	count += 2;
	count += ft_printf_hex((size_t)ptr, "0123456789abcdef");
	return (count);
}
