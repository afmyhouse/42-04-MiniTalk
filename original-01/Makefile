# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 14:52:10 by antoda-s          #+#    #+#              #
#    Updated: 2023/05/28 21:15:47 by antoda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary Names:
NAME = minitalk.a
CLIENT = client
SERVER = server

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

#Colors:
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RED			=	\e[38;5;196m
BLUE		=	\e[38:5:31m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

#SRCS		:= $(wildcard $(SRC)/*.c)

#COMPILE = $(CC) $(CFLAGS) $(INCLUDES)

all: executables
#$(CLIENT) $(SERVER)

executables: $(LIBFT)
#$(SERVER): $(LIBFT)
#	$(MAKE) -C ./libft
	@echo "[$(GREEN)all 002 - INFO$(RESET)] $(BLUE)Project : compile executables files$(RESET) $(SERVER) $(CLIENT)"
	$(CC) $(CFLAGS) server.c $(LIBFT) -o $(SERVER)
	$(CC) $(CFLAGS) client.c $(LIBFT) -o $(CLIENT)
#	@$(CC) $(CFLAGS) -I$(INCLUDE) $^ -o $@ $(LIBRARIES)
	@echo "[$(GREEN)all 002 - SUCCESS$(RESET)] $(BLUE)Project : compile executables files$(RESET) $(SERVER) $(CLIENT)"
	@echo



$(LIBFT):
	@echo "[$(GREEN)libft 001 - INFO$(RESET)] $(BLUE)Project : Compiling Libft$(RESET)$(YELLOW)"
	@$(MAKE) -C $(LIBFTDIR)
	@echo "$(RESET)[$(GREEN)libft 001 - SUCCESS$(RESET)] $(BLUE)Project : Compiling Libft$(RESET)"
	@echo

clean:
	@echo "[$(GREEN)clean 101 - INFO$(RESET)] Project : Cleaning Libs Objs$(YELLOW)"
	@$(MAKE) clean -C $(LIBFTDIR)
	@echo "$(RESET)[$(GREEN)clean 101 - SUCCESS$(RESET)] Project : Cleaning Libs Objs"
	@echo
	@echo "[$(GREEN)clean 102 - INFO$(RESET)] $(RED)Project Cleaning executables files$(RESET) $(SERVER) $(CLIENT)"
	$(RM) client server client_bonus server_bonus
	@echo "[$(GREEN)clean 102 - SUCCESS$(RESET)] $(RED)Project Cleaning executables files$(RESET) $(SERVER) $(CLIENT)"
	@echo

fclean: clean
	@echo "[$(GREEN)fclean 201 - INFO$(RESET)] $(RED)Project : Cleaning Libft.a$(RESET)$(YELLOW)"
	@$(MAKE) fclean -C $(LIBFTDIR)
	@echo "$(RESET)[$(GREEN)fclean 201 - SUCCESS$(RESET)] $(RED)Project : Cleaning Libft.a$(RESET)"
	@echo

re: fclean all

bonus:
	@echo
	@$(MAKE) -C ./libft
	@$(CC) $(CFLAGS) client_bonus.c $(LIBFT) -o client_bonus
	@$(CC) $(CFLAGS) server_bonus.c $(LIBFT) -o server_bonus