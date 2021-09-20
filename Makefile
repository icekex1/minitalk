# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 08:53:23 by tzeck             #+#    #+#              #
#    Updated: 2021/09/20 09:02:00 by tzeck            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

	# Library Name #
CLIENT = client
SERVER = server
	# libft Variables #
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft


	# Mandatory Variables #
SRC_C = client.c
SRC_S = server.c

	# Compiling Variables #
CC = gcc
CFLAG = -Wall -Wextra -Werror
RM = rm -f

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER): $(LIBFT)
	@ $(CC) $(CFLAG) $(SRC_S) $(LIBFT) -o $(SERVER)

$(CLIENT): $(LIBFT)
	@ $(CC) $(CFLAG) $(SRC_C) $(LIBFT) -o $(CLIENT)

$(LIBFT):
	@ $(MAKE) -C ./libft

clean:
	@ $(RM) $(CLIENT) $(SERVER)

fclean:
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(RM) $(CLIENT) $(SERVER)

re: fclean all

mandatory:	$(CLIENT) $(SERVER)
bonus:		mandatory

m : mandatory
b : bonus

.PHONY: all clean fclean re mandatory m bonus b
