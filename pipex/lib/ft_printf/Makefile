# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 14:57:33 by avilla-m          #+#    #+#              #
#    Updated: 2021/04/22 19:29:11 by avilla-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

SRCS =		$(wildcard *.c) $(wildcard libft/*.c) $(wildcard utils/*.c)
OBJS =		$(SRCS:.c=.o)

BSRCS =		$(wildcard bonus/*.c)
BOBJS =		$(BSRCS:.c=.o)

CFLAGS =	-Wall -Wextra -Werror -I.
GREEN 				= \033[01;32m
RESET 				= \033[00m

%.o:		%.c
			@gcc -c $(CFLAGS) $< -o $@

$(NAME):	$(OBJS) $(BOBJS)
			@ar rcs $(NAME) $(OBJS) $(BOBJS)
			@echo "\n$(GREEN)$(NAME) successfully compiled $(RESET)"

all:		$(NAME)

bonus:		$(NAME)

clean:
			@rm -f $(OBJS) $(BOBJS)
			@echo "$(GREEN)Successfully cleaned objects  - $(NAME)$(RESET)"

fclean:		clean
			@rm -f $(OBJS) $(BOBJS)
			@rm -f $(NAME)
			@echo "$(GREEN)Successfully forced cleaned - $(NAME)$(RESET)"


re:			fclean all

.PHONY:		all clean fclean re
