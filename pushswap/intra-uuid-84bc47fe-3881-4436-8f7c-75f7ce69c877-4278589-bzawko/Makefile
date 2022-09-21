SRCS	=	push_swap.c libft_funcs.c cost_calculation.c \
			swap_funcs_a.c swap_funcs_b.c swap_funcs_ab.c \
			misc_functions.c indexes_positions.c \
			misc_functions_2.c

BONUS_SRCS	=	bonus_checker.c bonus_line_funcs.c \
			bonus_stack_funcs.c bonus_swap_funcs_a.c \
			bonus_swap_funcs_b.c bonus_swap_funcs_ab.c

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -o

NAME	= push_swap

BONUS_NAME	= checker

all:	$(NAME)

$(NAME):
		$(CC) $(CFLAGS) $(NAME) $(SRCS)

clean:
		$(RM) $(NAME)

fclean:	clean

re:		fclean $(NAME)

bonus:
		$(CC) $(CFLAGS) $(BONUS_NAME) $(BONUS_SRCS)

.PHONY:	all clean fclean re bonus
