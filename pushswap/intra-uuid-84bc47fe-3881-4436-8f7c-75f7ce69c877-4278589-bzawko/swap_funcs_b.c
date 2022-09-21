/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:11:52 by bzawko            #+#    #+#             */
/*   Updated: 2022/08/19 13:11:53 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_struct	*sb(struct s_struct *stack_b)
{
	struct s_struct	*buffer;

	buffer = stack_b->next;
	stack_b->next = buffer->next;
	buffer->next = stack_b;
	write(1, "sb\n", 3);
	return (buffer);
}

struct s_struct	*rb(struct s_struct *stack_b)
{
	struct s_struct	*ret;
	struct s_struct	*buffer;

	ret = stack_b->next;
	buffer = stack_b;
	stack_b = stack_b->next;
	buffer->next = NULL;
	while (stack_b->next)
		stack_b = stack_b->next;
	stack_b->next = buffer;
	write(1, "rb\n", 3);
	return (ret);
}

struct s_struct	*rrb(struct s_struct *stack_b)
{
	struct s_struct	*start;
	struct s_struct	*buffer;

	start = stack_b;
	while (stack_b->next->next)
		stack_b = stack_b->next;
	buffer = stack_b->next;
	stack_b->next = NULL;
	buffer->next = start;
	write(1, "rrb\n", 4);
	return (buffer);
}

void	pb(struct s_struct **stack_a, struct s_struct **stack_b)
{
	struct s_struct	*buffer;

	if (!*stack_a)
		return ;
	buffer = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = buffer;
	write(1, "pb\n", 3);
}
