# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 14:52:10 by antoda-s          #+#    #+#              #
#    Updated: 2023/05/18 14:52:12 by antoda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

LIBFT = ./libft/libft.a

CLIENT = client

SERVER = server

all: $(CLIENT) $(SERVER)

$(SERVER):
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) server.c $(LIBFT) -o server

$(CLIENT):
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) client.c $(LIBFT) -o client


clean:
	$(MAKE) clean -C ./libft
	rm -rf client server client_bonus server_bonus

fclean: clean
	$(MAKE) fclean -C ./libft

re: fclean all

bonus:
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) client_bonus.c $(LIBFT) -o client_bonus
	$(CC) $(CFLAGS) server_bonus.c $(LIBFT) -o server_bonus