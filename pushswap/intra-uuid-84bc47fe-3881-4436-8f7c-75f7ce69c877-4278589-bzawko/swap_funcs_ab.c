/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funcs_ab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:11:43 by bzawko            #+#    #+#             */
/*   Updated: 2022/08/19 13:11:45 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(struct s_struct **stack_a, struct s_struct **stack_b)
{
	struct s_struct	*start;
	struct s_struct	*buffer;

	start = *stack_a;
	while ((*stack_a)->next->next)
		*stack_a = (*stack_a)->next;
	buffer = (*stack_a)->next;
	(*stack_a)->next = NULL;
	buffer->next = start;
	*stack_a = buffer;
	start = *stack_b;
	while ((*stack_b)->next->next)
		*stack_b = (*stack_b)->next;
	buffer = (*stack_b)->next;
	(*stack_b)->next = NULL;
	buffer->next = start;
	*stack_b = buffer;
	write(1, "rrr\n", 4);
}

void	rr(struct s_struct **stack_a, struct s_struct **stack_b)
{
	struct s_struct	*buffer;
	struct s_struct	*start;

	start = (*stack_a)->next;
	buffer = *stack_a;
	*stack_a = start;
	buffer->next = NULL;
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = buffer;
	*stack_a = start;
	start = (*stack_b)->next;
	buffer = *stack_b;
	*stack_b = start;
	buffer->next = NULL;
	while ((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = buffer;
	*stack_b = start;
	write(1, "rr\n", 3);
}
