# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 14:52:10 by antoda-s          #+#    #+#              #
#    Updated: 2023/05/25 17:58:59 by antoda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

VPATH = src include

vpath %.c ./src

vpath %.h ./include

CC = cc

CFLAGS = -Wall -Werror -Wextra

LIBFT = lib/libft.a

CLIENT = client

SERVER = server

all: $(CLIENT) $(SERVER)

$(SERVER): $(LIBFT)
#	@echo make libft.a for server
#	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) server.c $(LIBFT) -o $@

$(CLIENT): $(LIBFT)
#	@echo make libft.a for client
#	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) client.c $^ -o $@

$(LIBFT) :
	@echo make libft.a
	$(MAKE) -C ./libft

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

.PHONY: all clean