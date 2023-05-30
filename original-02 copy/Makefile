# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 14:52:10 by antoda-s          #+#    #+#              #
#    Updated: 2023/05/29 23:07:05 by antoda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary Names:
NAME = minitalk.a
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

#Compiling Variables:
CC 			= cc
CFLAGS 		= -Wall -Werror -Wextra
RM			= rm -rf

#functions & variables libraries:
LIBFT = ./libft/libft.a
LIBFTDIR = ./libft

#Directory paths when compiling and required:
DBIN		:= bin
DSRC		:= src
DINCS		:= inc
DLIBS		:= lib

#Sources
SERVER_SRC	:= server.c
CLIENT_SRC	:= client.c
SERVER_BONUS_SRC	:= server_bonus.c
CLIENT_BONUS_SRC	:= client_bonus.c

#Colors:
GRN		=	\e[38;5;118m
YLW		=	\e[38;5;226m
RED		=	\e[38;5;196m
BLU		=	\e[38:5:31m
WTH		=	\e[0m
_SUCCESS	=	[$(GRN)DONE$(WTH)]
_INFO		=	[$(YLW)INFO$(WTH)]

#SRCS		:= $(wildcard $(SRC)/*.c)

#COMPILE = $(CC) $(CFLAGS) $(INCLUDES)

all: executables
#$(CLIENT) $(SERVER)

executables: $(LIBFT)
#$(SERVER): $(LIBFT)
#	$(MAKE) -C ./libft
	@echo "$(_INFO)"
	@echo "[$(BLU)Project MANDATORY : compile executables files$(WTH)]"
	$(CC) $(CFLAGS) server.c $(LIBFT) -o $(SERVER)
	$(CC) $(CFLAGS) client.c $(LIBFT) -o $(CLIENT)
#	@$(CC) $(CFLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)
	@echo "$(_SUCCESS)"
	@echo



$(LIBFT):
	@echo "$(_INFO)"
	@echo "[$(BLU)Compile Poject Libft$(WTH)]"
	@$(MAKE) -C $(LIBFTDIR)
	@echo "$(_SUCCESS)"
	@echo

clean:
	@echo "$(_INFO)"
	@echo "[$(RED)Clean Project Libs Objs$(WTH)]"
	@$(MAKE) clean -C $(LIBFTDIR)
	@echo "$(_SUCCESS)"
	@echo
	@echo "$(_INFO)"
	@echo "[$(RED)Clean Project executables files$(WTH)]"
	@$(RM) $(CLIENT)
	@echo "$(CLIENT) file removed!!"
	@$(RM) $(SERVER)
	@echo "$(SERVER) file removed!!"
	@$(RM) $(CLIENT_BONUS)
	@echo "$(CLIENT_BONUS) file removed!!"
	@$(RM) $(SERVER_BONUS)
	@echo "$(SERVER_BONUS) file removed!!"
	@echo "$(_SUCCESS)"
	@echo

fclean: clean
	@echo "$(_INFO)"
	@echo "[$(RED)Project : Cleaning Libft.a$(WTH)]"
	@$(MAKE) fclean -C $(LIBFTDIR)
	@echo "$(_SUCCESS)"
	@echo

re: fclean all

bonus: bonus_executables

bonus_executables: $(LIBFT)
	@echo "$(_INFO)"
	@echo "[$(BLU)Project BONUS: compile executables files$(WTH)]"
	$(CC) $(CFLAGS) $(CLIENT_BONUS_SRC) $(LIBFT) -o $(CLIENT_BONUS)
	$(CC) $(CFLAGS) $(SERVER_BONUS_SRC) $(LIBFT) -o $(SERVER_BONUS)
	@echo "$(_SUCCESS)"
	@echo