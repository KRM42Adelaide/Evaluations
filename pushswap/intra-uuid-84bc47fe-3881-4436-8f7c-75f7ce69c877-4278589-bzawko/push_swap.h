/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 15:04:53 by bzawko            #+#    #+#             */
/*   Updated: 2022/06/12 15:25:29 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_struct {
	int				index;
	int				value;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_struct	*next;
}	t_struct;

int				ft_abs(int i);
int				ft_atoi(const char *nptr);
int				is_sorted(struct s_struct *stack_a, struct s_struct *stack_b);
int				stack_size(struct s_struct *stack);
int				get_index(struct s_struct *current, struct s_struct *stack);
int				find_lowest_cost(struct s_struct *stack_b);
int				rotate_a(struct s_struct **stack_a, int rotations);
int				rotate_b(struct s_struct **stack_b, int rotations);

struct s_struct	*orient_a(struct s_struct *stack_a, \
		struct s_struct *start, int a_size);
struct s_struct	*make_stack(struct s_struct *stack, int argc, char **argv);
struct s_struct	*three_number_sort(struct s_struct *stack);
struct s_struct	*sa(struct s_struct *stack_a);
struct s_struct	*ra(struct s_struct *stack_a);
struct s_struct	*rra(struct s_struct *stack_a);
struct s_struct	*sb(struct s_struct *stack_b);
struct s_struct	*rb(struct s_struct *stack_b);
struct s_struct	*rrb(struct s_struct *stack_b);

void			pa(struct s_struct **stack_a, struct s_struct **stack_b);
void			pb(struct s_struct **stack_a, struct s_struct **stack_b);
void			rr(struct s_struct **stack_a, struct s_struct **stack_b);
void			rrr(struct s_struct **stack_a, struct s_struct **stack_b);
void			free_stack(struct s_struct *stack);
void			assign_indexes(struct s_struct *stack);
void			assign_target_pos(struct s_struct *stack_a, \
				struct s_struct *stack_b, int target_pos, \
				struct s_struct *start);
void			assign_pos(struct s_struct *stack_a, struct s_struct *stack_b);
void			calculate_cost(struct s_struct *stack_a, \
				struct s_struct *stack_b);
void			sort_stack(struct s_struct *stack_a, \
				struct s_struct *stack_b, int argc, int i);
void			sort_single(struct s_struct **stack_a, \
				struct s_struct **stack_b);
void			move_single(struct s_struct **stack_a, \
				struct s_struct **stack_b, struct s_struct *start);
void			rotate_single(struct s_struct **stack_a, \
				struct s_struct **stack_b, int a_rotations, int b_rotations);

#endif
