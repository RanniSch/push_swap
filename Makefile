# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 13:34:43 by rschlott          #+#    #+#              #
#    Updated: 2022/09/23 16:07:09 by rschlott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap

# ========= compilation ==============
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -f

HEADER		:=	push_swap.h
SRCS		:=	reading-copy.c	\
				lis.c	\
				operations.c	\

OBJS		:= ${SRCS:.c=.o}

# ============ rules ==================
all:		${NAME}

$(NAME):	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${SRCS}

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re