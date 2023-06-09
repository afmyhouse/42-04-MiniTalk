# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 14:52:10 by antoda-s          #+#    #+#              #
#    Updated: 2023/05/31 13:17:33 by antoda-s         ###   ########.fr        #
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

#Objects
CLI_OBJ		:= $(CLIENT_SRC:.c=.o)
SVR_OBJ		:= $(SERVER_SRC:.c=.o)
CLI_B_OBJ	:= $(CLIENT_B_SRC:.c=.o)
SVR_B_OBJ	:= $(SERVER_B_SRC:.c=.o)

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

$(SERVER): $(LIBFT) $(SVR_OBJ)
	@echo "$(_INFO)"
	@echo "[$(BLU)Project MANDATORY : compile $(GRN)$(@) file$(WTH)]"
	@$(CC) $(CFLAGS) $(SVR_OBJ) $(LIBFT) -o $@
	@echo "$(_SUCCESS)"
	@echo

$(CLIENT): $(LIBFT) $(CLI_OBJ)
	@echo "$(_INFO)"
	@echo "[$(BLU)Project MANDATORY : compile $(GRN)$(@) file$(WTH)]"
	@$(CC) $(CFLAGS) $(CLI_OBJ) $(LIBFT) -o $@
	@echo "$(_SUCCESS)"
	@echo

$(LIBFT):
	@echo "$(_INFO)"
	@echo "[$(BLU)Compile Poject Libft$(WTH)]"
	@$(MAKE) --no-print-directory -C $(LIBFTDIR)
	@echo "$(_SUCCESS)"
	@echo

clean:
	@echo "$(_INFO)"
	@echo "[$(RED)Clean Project Libs Objs$(WTH)]"
	@$(MAKE) clean -C $(LIBFTDIR)
	@echo "$(_SUCCESS)"
	@echo
	@echo "$(_INFO)"
	@echo "[$(RED)Clean Project object files$(WTH)]"
	@$(RM) $(CLI_OBJ)
	@echo "$(CLI_OBJ) file removed!!"
	@$(RM) $(SVR_OBJ)
	@echo "$(SVR_OBJ) file removed!!"
	@$(RM) $(CLI_B_OBJ)
	@echo "$(CLI_B_OBJ) file removed!!"
	@$(RM) $(SVR_B_OBJ)
	@echo "$(SVR_B_OBJ) file removed!!"
	@echo "$(_SUCCESS)"
	@echo

fclean: clean
	@echo "$(_INFO)"
	@echo "[$(RED)Project : Cleaning Libft.a$(WTH)]"
	@$(MAKE) fclean -C $(LIBFTDIR)
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

re: fclean all

bonus: $(CLIENT_B) $(SERVER_B)

$(SERVER_B): $(LIBFT) $(SVR_B_OBJ)
	@echo "$(_INFO)"
	@echo "[$(BLU)Project BONUS : compile $(GRN)$(@) file$(WTH)]"
	@$(CC) $(CFLAGS) $(SVR_B_OBJ) $(LIBFT) -o $@
	@echo "$(_SUCCESS)"
	@echo

$(CLIENT_B): $(LIBFT) $(CLI_B_OBJ)
	@echo "$(_INFO)"
	@echo "[$(BLU)Project BONUS : compile $(GRN)$(@) file$(WTH)]"
	@$(CC) $(CFLAGS) $(CLI_B_OBJ) $(LIBFT) -o $@
	@echo "$(_SUCCESS)"
	@echo

.PHONY: all clean fclean re bonus

.SILENT: