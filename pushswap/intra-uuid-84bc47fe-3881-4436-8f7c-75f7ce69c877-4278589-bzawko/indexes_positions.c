/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes_positions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:09:55 by bzawko            #+#    #+#             */
/*   Updated: 2022/08/19 13:09:56 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Actually calculates and returns the index of a specific stack->value*/
int	get_index(struct s_struct *current, struct s_struct *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (current->pos != stack->pos)
		{
			if (current->value == stack->value)
			{
				write(2, "Error\n", 6);
				exit(0);
			}
			if (current->value > stack->value)
				++index;
		}
		stack = stack->next;
	}
	return (index);
}

/* Assigns indexes based on the stack->value */
void	assign_indexes(struct s_struct *stack)
{
	struct s_struct	*current;

	current = stack;
	while (current)
	{
		current->index = get_index(current, stack);
		current = current->next;
	}
	return ;
}

void	assign_target_pos(struct s_struct *stack_a, struct s_struct *stack_b, \
		int target_pos, struct s_struct *start)
{
	while (stack_b)
	{
		stack_b->target_pos = 0;
		while (stack_a->next)
		{
			if ((stack_a->index < stack_b->index && \
				stack_a->next->index > stack_b->index) || \
				(((stack_a->index > stack_b->index && \
				stack_a->next->index > stack_b->index) || \
				(stack_a->index < stack_b->index && \
				stack_a->next->index < stack_b->index)) && \
				stack_a->next->index < stack_a->index))
			{
				stack_b->target_pos = target_pos;
				break ;
			}
			++target_pos;
			stack_a = stack_a->next;
		}
		stack_a = start;
		if (!stack_b->target_pos)
			stack_b->target_pos = 0;
		stack_b = stack_b->next;
		target_pos = 1;
	}
}

void	assign_pos(struct s_struct *stack_a, struct s_struct *stack_b)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		stack_a->pos = i;
		stack_a = stack_a->next;
		++i;
	}
	i = 0;
	while (stack_b)
	{
		stack_b->pos = i;
		stack_b = stack_b->next;
		++i;
	}
}

struct s_struct	*orient_a(struct s_struct *stack_a, \
		struct s_struct *start, int a_size)
{
	int	rotations;

	while (stack_a)
	{
		if (stack_a->index == 0)
		{
			if (stack_a->pos <= (a_size / 2))
			{
				rotations = stack_a->pos;
				while (rotations--)
					start = ra(start);
				return (start);
			}
			else
			{
				rotations = (a_size - stack_a->pos);
				while (rotations--)
					start = rra(start);
				return (start);
			}
		}
		stack_a = stack_a->next;
	}
	return (start);
}
