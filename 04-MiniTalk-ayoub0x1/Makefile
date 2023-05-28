# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 17:44:00 by aymoulou          #+#    #+#              #
#    Updated: 2023/05/28 21:10:52 by antoda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary Name:
NAME	=
CLIENT	=	client
SERVER	=	server

#Compiling Variables:
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -rf

#ft_printf Variables:
LIBFTPRINTF	=	./ft_printf/libftprintf.a
LIBFTPRINTF_DIR	=	./ft_printf

#minitalk variables
SRC_CLIENT	=	ft_client.c
SRC_SERVER	=	ft_server.c
OBJ_SERVER	=	ft_server.o
OBJ_CLIENT	=	ft_client.o
INC		=	ft_minitalk.h

#Colors:
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all: executables

executables: $(LIBFTPRINTF)
	@echo go to make server exe
	@ $(CC) $(CFLAGS) $(SRC_SERVER) $(LIBFTPRINTF) -o $(SERVER)
	@printf "$(_SUCCESS) server ready.\n"
	@ $(CC) $(CFLAGS) $(SRC_CLIENT) $(LIBFTPRINTF) -o $(CLIENT)
	@printf "$(_SUCCESS) client ready.\n"

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

$(LIBFTPRINTF):
	@echo go to make libftprintf
	@ $(MAKE) -C $(LIBFTPRINTF_DIR)
	@echo libftprintf done

clean:
	@ $(MAKE) clean -C $(LIBFTPRINTF_DIR)
	@ $(RM) $(OBJ_C) $(OBJ_S)
	@printf "$(_INFO) object files removed.\n"

fclean: clean
	@ $(MAKE) fclean -C $(LIBFTPRINTF_DIR)
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "$(_INFO) client removed.\n"
	@printf "$(_INFO) server removed.\n"

re: fclean all

.PHONY: all clean fclean re
