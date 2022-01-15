# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-iaz <yait-iaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 18:45:43 by yait-iaz          #+#    #+#              #
#    Updated: 2022/01/15 21:03:23 by yait-iaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_S = server.c utils.c
SRCS_C = client.c utils.c
OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)
SERVER = server
CLIENT = client
HEADER = minitalk.h

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_S)
	$(CC) $(FLAGS) $(OBJS_S) -o $(SERVER)

$(CLIENT): $(OBJS_C)
	$(CC) $(FLAGS) $(OBJS_C) -o $(CLIENT)

bonus : all

%.o : %.c
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJS_C) $(OBJS_S)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all