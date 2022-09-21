/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:08:27 by bzawko            #+#    #+#             */
/*   Updated: 2022/08/19 13:08:32 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		++i;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	long int	ret;
	int			negative;

	ret = 0;
	negative = 1;
	if (*nptr == '-')
	{
		if (*nptr == '-')
			negative = -1;
		++nptr;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		ret *= 10;
		ret += (*nptr - 48);
		++nptr;
	}
	if (ret < INT_MIN || ret > INT_MAX || \
			(*nptr < '0' && *nptr != '\0') || (*nptr > '9' && *nptr != '\0'))
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	return (ret * negative);
}

int	operate_two(char *operation, struct s_struct **stack_a, \
		struct s_struct **stack_b)
{
	if (!ft_strcmp(operation, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(operation, "rra\n"))
		*stack_a = rra(*stack_a);
	else if (!ft_strcmp(operation, "rrb\n"))
		*stack_b = rrb(*stack_b);
	else if (!ft_strcmp(operation, "rrr\n"))
		rrr(stack_a, stack_b);
	else if (!ft_strcmp(operation, "rb\n"))
		*stack_b = rb(*stack_b);
	else if (*operation == '\n')
		return (0);
	else
	{
		write(2, "Invalid Instruction\n", 20);
		exit(0);
	}
	return (0);
}

int	operate(char *operation, struct s_struct **stack_a, \
		struct s_struct **stack_b)
{
	if (!*operation)
		return (0);
	if (!ft_strcmp(operation, "sa\n"))
		*stack_a = sa(*stack_a);
	else if (!ft_strcmp(operation, "sb\n"))
		*stack_b = sb(*stack_b);
	else if (!ft_strcmp(operation, "ss\n"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(operation, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(operation, "pb\n"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(operation, "ra\n"))
		*stack_a = ra(*stack_a);
	else
		return (operate_two(operation, stack_a, stack_b));
	return (0);
}

int	main(int argc, char **argv)
{
	char			*list;
	struct s_struct	*stack_a;
	struct s_struct	*stack_b;

	if (argc == 0 || argc == 1)
		return (0);
	stack_b = NULL;
	stack_a = NULL;
	stack_a = make_stack(stack_a, argc, argv, 0);
	list = get_list(NULL);
	while (*list && *list != '\n')
	{
		operate(list, &stack_a, &stack_b);
		free(list);
		list = get_list(NULL);
	}
	free(list);
	if (is_sorted(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (stack_b)
		free_stack(stack_b);
	free_stack(stack_a);
	return (0);
}
