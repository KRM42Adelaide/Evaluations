/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzawko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 13:09:37 by bzawko            #+#    #+#             */
/*   Updated: 2022/08/19 13:09:38 by bzawko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

int				is_in_string(char *str, char x);
int				is_sorted(struct s_struct *stack_a, struct s_struct *stack_b);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strlen(char *str);
int				ft_atoi(const char *nptr);

char			*get_list(char *list);
char			*ft_strjoin(char *list, char *buffer);

void			check_duplicates(struct s_struct *stack);
void			free_stack(struct s_struct *stack);
void			pa(struct s_struct **stack_a, struct s_struct **stack_b);
void			pb(struct s_struct **stack_a, struct s_struct **stack_b);
void			rr(struct s_struct **stack_a, struct s_struct **stack_b);
void			rrr(struct s_struct **stack_a, struct s_struct **stack_b);
void			ss(struct s_struct **stack_a, struct s_struct **stack_b);

struct s_struct	*sa(struct s_struct *stack_a);
struct s_struct	*ra(struct s_struct *stack_a);
struct s_struct	*rra(struct s_struct *stack_a);
struct s_struct	*sb(struct s_struct *stack_b);
struct s_struct	*rb(struct s_struct *stack_b);
struct s_struct	*rrb(struct s_struct *stack_b);
struct s_struct	*make_stack(struct s_struct *stack, \
		int argc, char **argv, int i);

#endif
