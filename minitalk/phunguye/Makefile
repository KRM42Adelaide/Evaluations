# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/03 11:44:56 by phunguye          #+#    #+#              #
#    Updated: 2022/09/03 12:00:51 by phunguye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server.out
CLIENT = client.out
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SFILES = server.c libftprintf.a
CFILES = client.c libftprintf.a
INCLUDES = includes/

all : server client

server :
	$(CC) $(CFLAGS) -I $(INCLUDES) $(SFILES) -o $(SERVER)

client :
	$(CC) $(CFLAGS) -I $(INCLUDES) $(CFILES) -o $(CLIENT)

clean :
	rm -f $(SERVER)
	rm -f $(CLIENT)

re : clean all

.PHONY : clean all re