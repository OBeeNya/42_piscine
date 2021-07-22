# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baubigna <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 17:22:26 by baubigna          #+#    #+#              #
#    Updated: 2021/07/21 09:32:09 by baubigna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= do-op

SRCS			= main.c

RM				= rm -f

OBJS			= ${SRCS:.c=.o}

CC				= gcc -Wall -Werror -Wextra

all:			${NAME}

${NAME}:
				${CC} ${SRCS} -o ${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all
