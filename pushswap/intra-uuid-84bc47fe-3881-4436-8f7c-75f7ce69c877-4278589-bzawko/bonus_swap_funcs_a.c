/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_swap_funcs_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:09:06 by bzawko            #+#    #+#             */
/*   Updated: 2022/08/19 14:32:21 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

struct s_struct	*sa(struct s_struct *stack_a)
{
	struct s_struct	*buffer;

	if (!stack_a)
		return (NULL);
	if (!stack_a->next)
		return (stack_a);
	buffer = stack_a->next;
	stack_a->next = buffer->next;
	buffer->next = stack_a;
	return (buffer);
}

struct s_struct	*ra(struct s_struct *stack_a)
{
	struct s_struct	*ret;
	struct s_struct	*buffer;

	if (!stack_a)
		return (NULL);
	if (!stack_a->next)
		return (stack_a);
	ret = stack_a->next;
	buffer = stack_a;
	stack_a = stack_a->next;
	buffer->next = NULL;
	while (stack_a->next)
		stack_a = stack_a->next;
	stack_a->next = buffer;
	return (ret);
}

struct s_struct	*rra(struct s_struct *stack_a)
{
	struct s_struct	*start;
	struct s_struct	*buffer;

	if (!stack_a)
		return (NULL);
	if (!stack_a->next)
		return (stack_a);
	start = stack_a;
	while (stack_a->next->next)
		stack_a = stack_a->next;
	buffer = stack_a->next;
	stack_a->next = NULL;
	buffer->next = start;
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
}
