/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_swap_funcs_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:09:25 by bzawko            #+#    #+#             */
/*   Updated: 2022/08/19 14:33:23 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

struct s_struct	*sb(struct s_struct *stack_b)
{
	struct s_struct	*buffer;

	if (!stack_b)
		return (NULL);
	if (!stack_b->next)
		return (stack_b);
	buffer = stack_b->next;
	stack_b->next = buffer->next;
	buffer->next = stack_b;
	return (buffer);
}

struct s_struct	*rb(struct s_struct *stack_b)
{
	struct s_struct	*ret;
	struct s_struct	*buffer;

	if (!stack_b)
		return (NULL);
	if (!stack_b->next)
		return (stack_b);
	ret = stack_b->next;
	buffer = stack_b;
	stack_b = stack_b->next;
	buffer->next = NULL;
	while (stack_b->next)
		stack_b = stack_b->next;
	stack_b->next = buffer;
	return (ret);
}

struct s_struct	*rrb(struct s_struct *stack_b)
{
	struct s_struct	*start;
	struct s_struct	*buffer;

	if (!stack_b)
		return (NULL);
	if (!stack_b->next)
		return (stack_b);
	start = stack_b;
	while (stack_b->next->next)
		stack_b = stack_b->next;
	buffer = stack_b->next;
	stack_b->next = NULL;
	buffer->next = start;
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
}
