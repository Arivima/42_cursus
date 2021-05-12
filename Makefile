# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/18 16:42:30 by avilla-m          #+#    #+#              #
#    Updated: 2021/01/26 16:14:20 by avilla-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libft.a

SRCS = 		${wildcard *.c}
OBJS = 		${SRCS:.c=.o}
MAIN =		${wildcard main*.c}

RM = 		rm -f
CC = 		gcc
CFLAGS = 	-Wall -Wextra -Werror

%.o :		%.c 		
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: 	${OBJS}
			ar rcs ${NAME} ${OBJS}

all: 		${NAME}

clean :
			${RM} ${OBJS}

fclean : 	clean
			${RM} ${NAME}

re : 		fclean all


compile :	 ${MAIN} all
			${CC} -L. -lft ${MAIN}
run :		compile
			./a.out


git : 		fclean 
			${RM} ./a.out 
			${RM} .DS_Store
			git status && echo "-----------------------"
			git add ./. && echo "-----------------------"
			git status && echo "-----------------------"
			git commit -m "automatic update" && echo "-----------------------"
			git status && echo "-----------------------"
			git push && echo "-----------------------"
			git status && echo "-----------------------"

.PHONY: 	all clean fclean re compile run git


