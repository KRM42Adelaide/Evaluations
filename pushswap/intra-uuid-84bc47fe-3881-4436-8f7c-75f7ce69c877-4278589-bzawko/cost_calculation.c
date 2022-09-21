/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:09:46 by bzawko            #+#    #+#             */
/*   Updated: 2022/08/19 13:09:47 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

void	calculate_cost(struct s_struct *stack_a, struct s_struct *stack_b)
{
	int				a_size;
	int				b_size;
	struct s_struct	*start;

	a_size = stack_size(stack_a);
	b_size = stack_size(stack_b);
	start = stack_b;
	while (stack_b)
	{
		if (stack_b->target_pos <= (a_size / 2))
			stack_b->cost_a = stack_b->target_pos;
		else
			stack_b->cost_a = ((a_size - stack_b->target_pos) * -1);
		stack_b = stack_b->next;
	}
	while (start)
	{
		if (start->pos <= (b_size / 2))
			start->cost_b = start->pos;
		else
			start->cost_b = ((b_size - start->pos) * -1);
		start = start->next;
	}
}

int	find_lowest_cost(struct s_struct *stack_b)
{
	int	ret;

	ret = (ft_abs(stack_b->cost_a) + ft_abs(stack_b->cost_b));
	while (stack_b)
	{
		if ((ft_abs(stack_b->cost_a) + ft_abs(stack_b->cost_b)) < ret)
			ret = (ft_abs(stack_b->cost_a) + ft_abs(stack_b->cost_b));
		stack_b = stack_b->next;
	}
	return (ret);
}
