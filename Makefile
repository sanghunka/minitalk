# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghun <sankang@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 16:34:06 by sanghun           #+#    #+#              #
#    Updated: 2022/06/02 01:36:05 by sanghun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = minitalk
NAME_SERVER = server
NAME_CLIENT = client
SRC_SERVER = server.c
SRC_CLIENT = client.c
LIBFT_DIR = libft/

all: $(NAME)

$(NAME):
	@make all -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft $(SRC_SERVER) -o $(NAME_SERVER)
	@$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft $(SRC_CLIENT) -o $(NAME_CLIENT)
	@touch $(NAME)

clean:
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME)

re: fclean all

.PHONY: clean fclean re all