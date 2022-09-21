/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:11:34 by bzawko            #+#    #+#             */
/*   Updated: 2022/08/19 13:11:35 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_struct	*sa(struct s_struct *stack_a)
{
	struct s_struct	*buffer;

	buffer = stack_a->next;
	stack_a->next = buffer->next;
	buffer->next = stack_a;
	write(1, "sa\n", 3);
	return (buffer);
}

struct s_struct	*ra(struct s_struct *stack_a)
{
	struct s_struct	*ret;
	struct s_struct	*buffer;

	ret = stack_a->next;
	buffer = stack_a;
	stack_a = stack_a->next;
	buffer->next = NULL;
	while (stack_a->next)
		stack_a = stack_a->next;
	stack_a->next = buffer;
	write(1, "ra\n", 3);
	return (ret);
}

struct s_struct	*rra(struct s_struct *stack_a)
{
	struct s_struct	*start;
	struct s_struct	*buffer;

	start = stack_a;
	while (stack_a->next->next)
		stack_a = stack_a->next;
	buffer = stack_a->next;
	stack_a->next = NULL;
	buffer->next = start;
	write(1, "rra\n", 4);
	return (buffer);
}

void	pa(struct s_struct **stack_a, struct s_struct **stack_b)
{
	struct s_struct	*buffer;

	if (!*stack_b)
		return ;
	buffer = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = buffer;
	write(1, "pa\n", 3);
}
