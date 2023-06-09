# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 14:52:10 by antoda-s          #+#    #+#              #
#    Updated: 2023/05/30 16:19:15 by antoda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary Names:
NAME = minitalk.a
CLIENT = client
SERVER = server
CLIENT_B = client_bonus
SERVER_B = server_bonus

#Compiling Variables:
CC 			= cc
CFLAGS 		= -Wall -Werror -Wextra
RM			= rm -rf

#functions & variables libraries:
LIBFT = ./libft/libft.a
LIBFTDIR = ./libft

#Directory paths when compiling and required:
#DBIN		:= bin
#DSRC		:= src
#DINCS		:= inc
#DLIBS		:= lib

#Sources
SERVER_SRC		:= server.c
CLIENT_SRC		:= client.c
SERVER_B_SRC	:= server_bonus.c
CLIENT_B_SRC	:= client_bonus.c

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

all: $(CLIENT) $(SERVER)

$(SERVER): $(LIBFT)
	@echo "$(_INFO)"
	@echo "[$(BLU)Project MANDATORY : compile $(GRN)$(@) file$(WTH)]"
	@$(CC) $(CFLAGS) $(SERVER_SRC) $(LIBFT) -o $@
	@echo "$(_SUCCESS)"
	@echo

$(CLIENT): $(LIBFT)
	@echo "$(_INFO)"
	@echo "[$(BLU)Project MANDATORY : compile $(GRN)$(@) file$(WTH)]"
	@$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIBFT) -o $@
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
	@$(RM) $(CLIENT_B)
	@echo "$(CLIENT_B) file removed!!"
	@$(RM) $(SERVER_B)
	@echo "$(SERVER_B) file removed!!"
	@echo "$(_SUCCESS)"
	@echo

fclean: clean
	@echo "$(_INFO)"
	@echo "[$(RED)Project : Cleaning Libft.a$(WTH)]"
	@$(MAKE) fclean -C $(LIBFTDIR)
	@echo "$(_SUCCESS)"
	@echo

re: fclean all

bonus: $(CLIENT_B) $(SERVER_B)

$(SERVER_B): $(LIBFT)
	@echo "$(_INFO)"
	@echo "[$(BLU)Project BONUS : compile $(GRN)$(@) file$(WTH)]"
	@$(CC) $(CFLAGS) $(SERVER_B_SRC) $(LIBFT) -o $@
	@echo "$(_SUCCESS)"
	@echo

$(CLIENT_B): $(LIBFT)
	@echo "$(_INFO)"
	@echo "[$(BLU)Project BONUS : compile $(GRN)$(@) file$(WTH)]"
	@$(CC) $(CFLAGS) $(CLIENT_B_SRC) $(LIBFT) -o $@
	@echo "$(_SUCCESS)"
	@echo

.PHONY: all clean fclean re bonus