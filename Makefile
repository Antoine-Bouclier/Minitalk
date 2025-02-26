# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 10:06:59 by abouclie          #+#    #+#              #
#    Updated: 2025/02/26 16:00:08 by abouclie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RESET = \033[0m

CC		= cc
RM		= rm -rf
MKDIR	= mkdir -p

CFLAGS	= -Wall -Wextra -Werror -MMD -MP

CLIENT			= client
SERVER			= server
CLT_SRCS		= client.c
SRV_SRCS		= server.c

OBJ_DIR			= obj
DEP_DIR			= dep

CLT_OBJS 		= $(addprefix $(OBJ_DIR)/, $(CLT_SRCS:.c=.o))
SRV_OBJS 		= $(addprefix $(OBJ_DIR)/, $(SRV_SRCS:.c=.o))
DEPS			= $(addprefix $(DEP_DIR)/, $(CLT_SRCS:.c=.d) $(SRV_SRCS:.c=.d))

LIBFT			= libft
HEADER			= $(LIBFT)/libft.h
LIBFLAGS		= $(LIBFT)/libft.a

MAKEFILE		= Makefile

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLT_OBJS) $(LIBFLAGS) $(MAKEFILE)
	$(CC) $(CFLAGS) $(CLT_OBJS) -o $(CLIENT) $(LIBFLAGS)
	@printf "Client	$(GREEN)[OK]$(RESET)\n"

$(SERVER): $(SRV_OBJS) $(LIBFLAGS) $(MAKEFILE)
	$(CC) $(CFLAGS) $(SRV_OBJS)  -o $(SERVER) $(LIBFLAGS)
	@printf "Server	$(GREEN)[OK]$(RESET)\n"

$(OBJ_DIR)/%.o: %.c $(MAKEFILE)
	@$(MKDIR) $(OBJ_DIR) $(DEP_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -MF $(DEP_DIR)/$*.d

$(LIBFLAGS):
	$(MAKE) -C $(LIBFT)

clean:
	$(RM) $(OBJ_DIR) $(DEP_DIR)
	$(MAKE) -C $(LIBFT) clean
	@printf "clean	$(GREEN)[OK]$(RESET)\n"

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	$(MAKE) -C $(LIBFT) fclean
	@printf "fclean	$(GREEN)[OK]$(RESET)\n"

re:	fclean all

.PHONY: clean fclean all re

-include $(DEPS)
