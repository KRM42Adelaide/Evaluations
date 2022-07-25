# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanguyen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 11:23:03 by hanguyen          #+#    #+#              #
#    Updated: 2022/07/25 11:12:50 by kmachaka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS =  -Wall -Wextra -Werror

SRCS = *.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
		$(CC) $(CFLAGS) -I . -c $(SRCS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		-rm $(OBJS)

fclean:	clean
		-rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
