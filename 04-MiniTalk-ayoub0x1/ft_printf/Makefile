# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antoda-s <antoda-s@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 15:38:53 by aymoulou          #+#    #+#              #
#    Updated: 2023/05/28 21:07:56 by antoda-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -I.
ARCH			= ar rcs
RM				= rm -f

SRCS=    ft_printf.c ft_putaddr.c ft_putchar.c ft_putnbr.c \
            ft_putnbr_base.c ft_putstr.c ft_putnbr_u.c ft_atoi.c

OBJS	= ${SRCS:.c=.o}

NAME	= libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
