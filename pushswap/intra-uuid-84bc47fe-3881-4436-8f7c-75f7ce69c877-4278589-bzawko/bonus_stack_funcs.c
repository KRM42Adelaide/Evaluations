/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_stack_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:08:53 by bzawko            #+#    #+#             */
/*   Updated: 2022/08/19 13:08:55 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_in_string(char *str, char x)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == x)
			return (1);
		++str;
	}
	return (0);
}

int	is_sorted(struct s_struct *stack_a, struct s_struct *stack_b)
{
	if (stack_b)
		return (0);
	while (stack_a)
	{
		stack_b = stack_a->next;
		while (stack_b)
		{
			if (stack_b->value < stack_a->value)
				return (0);
			stack_b = stack_b->next;
		}
		stack_a = stack_a->next;
	}
	return (1);
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

void	check_duplicates(struct s_struct *stack)
{
	struct s_struct	*stack_2;
	struct s_struct	*start;

	start = stack;
	stack_2 = stack->next;
	while (stack)
	{
		while (stack_2)
		{
			if (stack_2->value == stack->value)
			{
				write(2, "Error: Duplicate\n", 17);
				free_stack(start);
				exit(0);
			}
			stack_2 = stack_2->next;
			if (stack_2 == stack)
				stack_2 = stack_2->next;
		}
		stack = stack->next;
		stack_2 = start;
	}
}

struct s_struct	*make_stack(struct s_struct *stack, \
		int argc, char **argv, int i)
{
	struct s_struct	*ret;

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
	check_duplicates(ret);
	return (ret);
}
