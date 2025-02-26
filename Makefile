# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 10:06:59 by abouclie          #+#    #+#              #
#    Updated: 2025/02/26 09:56:58 by abouclie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

CC		= cc
RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror

CLIENT			= client
SERVER			= server
CLT_OBJS 		= client.o
SRV_OBJS 		= server.o

LIBFT			= libft
HEADER			= $(LIBFT)/libft.h
LIBFLAGS		= $(LIBFT)/libft.a

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLT_OBJS) $(HEADER) $(LIBFLAGS)
	$(CC) $(CFLAGS) $(CLT_OBJS) -o $(CLIENT) $(LIBFLAGS)
	printf "Client		[OK]\n"

$(SERVER): $(SRV_OBJS) $(UTL_OBJS) $(HEADER) $(LIBFLAGS)
	$(CC) $(CFLAGS) $(SRV_OBJS)  -o $(SERVER) $(LIBFLAGS)
	printf "Server		[OK]\n"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(CLT_OBJS) $(SRV_OBJS)
	printf "clean		[OK]\n"

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	printf "fclean		[OK]\n"

re:	fclean all

.PHONY: clean fclean all re