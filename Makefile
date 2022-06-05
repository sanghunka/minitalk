# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sankang <sankang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 16:34:06 by sanghun           #+#    #+#              #
#    Updated: 2022/06/05 21:30:44 by sankang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = minitalk
NAME_SERVER = server
NAME_CLIENT = client
SRC_SERVER = server.c
SRC_CLIENT = client.c
B_SRC_SERVER = server_bonus.c
B_SRC_CLIENT = client_bonus.c
LIBFT_DIR = libft/

all: server client

$(NAME): all

libft:
	make all -C $(LIBFT_DIR)

server: libft
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft $(SRC_SERVER) -o $(NAME_SERVER)

client: libft
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft $(SRC_CLIENT) -o $(NAME_CLIENT)

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME_SERVER) $(NAME_CLIENT)

bonus: libft
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft $(B_SRC_SERVER) -o $(NAME_SERVER)
	$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft $(B_SRC_CLIENT) -o $(NAME_CLIENT)

re: fclean all

.PHONY: clean fclean re all libft bonus minitalk