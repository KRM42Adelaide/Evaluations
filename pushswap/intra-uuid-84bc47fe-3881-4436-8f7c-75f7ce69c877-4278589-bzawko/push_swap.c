/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:11:11 by bzawko            #+#    #+#             */
/*   Updated: 2022/08/19 16:02:04 by kmachaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_single(struct s_struct **stack_a, struct s_struct **stack_b, \
	int a_rotations, int b_rotations)
{
	while (a_rotations > 0 && b_rotations > 0)
	{
		--a_rotations;
		--b_rotations;
		rr(stack_a, stack_b);
	}
	while (a_rotations < 0 && b_rotations < 0)
	{
		++a_rotations;
		++b_rotations;
		rrr(stack_a, stack_b);
	}
	while (a_rotations)
	{
		a_rotations += rotate_a(stack_a, a_rotations);
	}
	while (b_rotations)
	{
		b_rotations += rotate_b(stack_b, b_rotations);
	}
}

void	move_single(struct s_struct **stack_a, struct s_struct **stack_b, \
	struct s_struct *start)
{
	int	a_rotations;
	int	b_rotations;

	a_rotations = (*stack_b)->cost_a;
	b_rotations = (*stack_b)->cost_b;
	*stack_b = start;
	rotate_single(stack_a, stack_b, a_rotations, b_rotations);
	pa(stack_a, stack_b);
}

void	sort_single(struct s_struct **stack_a, struct s_struct **stack_b)
{
	int				cheapest;
	struct s_struct	*start;

	cheapest = find_lowest_cost(*stack_b);
	start = *stack_b;
	while (*stack_b)
	{
		if ((ft_abs((*stack_b)->cost_a) + ft_abs((*stack_b)->cost_b)) == \
				cheapest)
		{
			move_single(stack_a, stack_b, start);
			return ;
		}
		*stack_b = (*stack_b)->next;
	}
}

void	sort_stack(struct s_struct *stack_a, struct s_struct *stack_b, \
		int argc, int i)
{
	while (i < (argc / 2) && stack_a->next->next->next)
	{
		if ((stack_a->index / 2) < (argc / 2))
		{
			pb(&stack_a, &stack_b);
			++i;
		}
		else
			stack_a = ra(stack_a);
	}
	while (stack_a->next->next->next)
		pb(&stack_a, &stack_b);
	stack_a = three_number_sort(stack_a);
	while (stack_b)
	{
		assign_pos(stack_a, stack_b);
		assign_target_pos(stack_a, stack_b, 1, stack_a);
		calculate_cost(stack_a, stack_b);
		sort_single(&stack_a, &stack_b);
	}
	assign_pos(stack_a, stack_b);
	stack_a = orient_a(stack_a, stack_a, stack_size(stack_a));
	stack_b = stack_a;
	free_stack(stack_a);
}

int	main(int argc, char **argv)
{
	struct s_struct	*stack_a;

	if (argc < 3)
		exit(0);
	stack_a = NULL;
	stack_a = make_stack(stack_a, argc, argv);
	assign_indexes(stack_a);
	if (is_sorted(stack_a, NULL))
		exit(0);
	if (argc == 4)
	{
		stack_a = three_number_sort(stack_a);
		return (0);
	}
	if (argc == 3)
		return ((write(1, "sa\n", 3) - 3));
	sort_stack(stack_a, NULL, argc - 1, 0);
	return (0);
}
