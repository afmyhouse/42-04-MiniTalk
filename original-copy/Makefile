# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 14:52:10 by antoda-s          #+#    #+#              #
#    Updated: 2023/05/25 23:36:56 by antoda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

CC 			= cc
CFLAGS 		= -Wall -Werror -Wextra
RM			= rm -rf

DBIN		:= bin
DSRC		:= src
DINCS		:= inc
DLIBS		:= lib

#SRCS		:= $(wildcard $(SRC)/*.c)

LIBFT = ./libft/libft.a

#EXECUTABLES	:= client server
CLIENT = client
SERVER = server

#COMPILE          = $(CC) $(CFLAGS) $(INCLUDES)

all: executables
#$(CLIENT) $(SERVER)

executables: $(LIBFT)
#$(SERVER): $(LIBFT)
#	$(MAKE) -C ./libft
	@echo STEP 1
	@echo Project : compile executables
	@$(CC) $(CFLAGS) server.c $(LIBFT) -o $(SERVER)
	@$(CC) $(CFLAGS) client.c $(LIBFT) -o $(CLIENT)
#	@$(CC) $(CFLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)
	@echo STEP 1 done!
	@echo



$(LIBFT):
	@echo STEP 0
	@echo Project : Compiling Libft...
	@echo
	@$(MAKE) -C ./libft
	@echo STEP 0 done!
	@echo

clean:
	@echo Project : Cleaning Libs Objs...
	@$(MAKE) clean -C ./libft
	@echo Project : Cleaning Libs Objs done!
	@echo
	@echo Project Cleaning executables files $(SERVER) $(CLIENT)...
	@echo ...
	@$(RM) client server client_bonus server_bonus
	@echo Project : Cleaning executables files $(SERVER) $(CLIENT) done!

fclean: clean
#	$(RM) $(NAME)
#	$(RM) client server client_bonus server_bonus
	@echo Project : Cleaning Libft.a
	@$(MAKE) fclean -C ./libft
	@echo Project : Cleaning Libft.a done!

re: fclean all

bonus:
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) client_bonus.c $(LIBFT) -o client_bonus
	$(CC) $(CFLAGS) server_bonus.c $(LIBFT) -o server_bonus