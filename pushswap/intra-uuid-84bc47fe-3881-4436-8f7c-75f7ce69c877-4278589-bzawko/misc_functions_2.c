/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:11:02 by bzawko            #+#    #+#             */
/*   Updated: 2022/08/19 13:11:03 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(struct s_struct **stack_a, int rotations)
{
	if (rotations > 0)
	{
		*stack_a = ra(*stack_a);
		return (-1);
	}
	else if (rotations < 0)
	{
		*stack_a = rra(*stack_a);
		return (1);
	}
	return (0);
}

int	rotate_b(struct s_struct **stack_b, int rotations)
{
	if (rotations > 0)
	{
		*stack_b = rb(*stack_b);
		return (-1);
	}
	else if (rotations < 0)
	{
		*stack_b = rrb(*stack_b);
		return (1);
	}
	return (0);
}
