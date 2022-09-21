/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:10:35 by bzawko            #+#    #+#             */
/*   Updated: 2022/08/19 13:10:40 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks if the stack is sorted */
int	is_sorted(struct s_struct *stack_a, struct s_struct *stack_b)
{
	if (stack_b)
		return (0);
	while (stack_a)
	{
		stack_b = stack_a->next;
		while (stack_b)
		{
			if (stack_b->index < stack_a->index)
				return (0);
			stack_b = stack_b->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
}

/* Returns the number of elements in a stack*/
int	stack_size(struct s_struct *stack)
{
	int	ret;

	ret = 0;
	while (stack)
	{
		stack = stack->next;
		++ret;
	}
	return (ret);
}

/* Allocates the space for the stack and links the list together*/
struct s_struct	*make_stack(struct s_struct *stack, int argc, char **argv)
{
	int				i;
	struct s_struct	*ret;

	i = 0;
	while (++i < argc)
	{
		if (stack)
		{
			stack->next = malloc(sizeof(t_struct));
			if (!stack->next)
				exit(0);
			stack = stack->next;
		}
		else
		{
			stack = malloc(sizeof(t_struct));
			if (!stack)
				exit(0);
			ret = stack;
		}
		stack->value = ft_atoi(argv[i]);
		stack->pos = (i - 1);
	}
	stack->next = NULL;
	return (ret);
}

/* Sorting algorithm for three elements*/
struct s_struct	*three_number_sort(struct s_struct *stack)
{
	if (is_sorted(stack, NULL))
		return (stack);
	if (stack->index > stack->next->index && \
			stack->index > stack->next->next->index)
	{
		if (stack->next->index > stack->next->next->index)
		{
			stack = ra(stack);
			stack = sa(stack);
			return (stack);
		}
		else
			return (ra(stack));
	}
	if (stack->index > stack->next->index || \
			stack->index > stack->next->next->index)
	{
		if (stack->index > stack->next->index)
			return (sa(stack));
		else
			return (rra(stack));
	}
	stack = sa(stack);
	return (ra(stack));
}

void	free_stack(struct s_struct *stack)
{
	struct s_struct	*buffer;

	while (stack)
	{
		buffer = stack->next;
		free(stack);
		stack = buffer;
	}
}
