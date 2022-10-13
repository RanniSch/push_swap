# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 13:34:43 by rschlott          #+#    #+#              #
#    Updated: 2022/10/13 06:35:34 by rschlott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap

# ========= compilation ==============
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -f

HEADER		:=	push_swap.h
SRCS		:=	reading.c	\
				error_manager.c	\
				lis.c	\
				operations_swap.c	\
				operations_push.c	\
				operations_rev_rotate.c	\
				operations_rotate.c	\
				minimum_sorting.c	\

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