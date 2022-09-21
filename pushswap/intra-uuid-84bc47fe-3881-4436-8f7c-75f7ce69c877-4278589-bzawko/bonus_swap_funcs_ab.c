/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_swap_funcs_ab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:09:16 by bzawko            #+#    #+#             */
/*   Updated: 2022/08/19 14:38:43 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rrr(struct s_struct **stack_a, struct s_struct **stack_b)
{
	*stack_a = rra(*stack_a);
	*stack_b = rrb(*stack_b);
}

void	rr(struct s_struct **stack_a, struct s_struct **stack_b)
{
	*stack_a = ra(*stack_a);
	*stack_b = rb(*stack_b);
}

void	ss(struct s_struct **stack_a, struct s_struct **stack_b)
{
	if (*stack_a)
		*stack_a = sa(*stack_a);
	if (*stack_b)
		*stack_b = sb(*stack_b);
}
