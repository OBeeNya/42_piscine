# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baubigna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 17:59:04 by baubigna          #+#    #+#              #
#    Updated: 2021/07/14 19:08:21 by baubigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS		= srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c \
			  srcs/ft_strlen.c srcs/ft_strcmp.c

INCLUDES	= includes/

OBJS		= ${SRCS:.c=.o}

GCC			= gcc

RM			= rm -f

GFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

.c.o:
			${GCC} ${GFLAGS} -c $< -o ${<:.c=.o} -I${INCLUDES}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}

clean:		
			RM ${OBJS}

fclean:		clean
			RM ${NAME}

re:			fclean all
