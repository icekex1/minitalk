# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 08:53:23 by tzeck             #+#    #+#              #
#    Updated: 2021/09/21 18:25:08 by tzeck            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft

SRC_C = client.c
SRC_S = server.c

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

bonus:	all

m : mandatory
b : bonus

.PHONY: all clean fclean re
