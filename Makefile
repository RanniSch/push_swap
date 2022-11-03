# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 13:34:43 by rschlott          #+#    #+#              #
#    Updated: 2022/11/03 12:49:39 by rschlott         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap

# ========= compilation ==============
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -f

HEADER		:=	push_swap.h
SRCS		:=	./tools/main.c	\
				./tools/reading.c	\
				./tools/global_utils.c	\
				./tools/error_manager.c	\
				./few_args/all_args.c	\
				./few_args/utils.c	\
				./few_args/five_args_utils.c	\
				./longest_increasing_subsequence/lis_utils.c	\
				./longest_increasing_subsequence/lis.c	\
				./operations/operations_swap.c	\
				./operations/operations_push.c	\
				./operations/operations_rev_rotate.c	\
				./operations/operations_rotate.c	\
				./operations/array_operations.c	\
				minimum_sorting.c
							

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