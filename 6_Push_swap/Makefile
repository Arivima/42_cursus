# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 14:11:54 by avilla-m          #+#    #+#              #
#    Updated: 2021/10/21 14:11:57 by avilla-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				push_swap
SRCS_DIR			= ./srcs_push_swap
LIBFT_DIR			= ./libft
LIBFT_A				= $(LIBFT_DIR)/libft.a
HEAD_DIR			= ./include 

SRCS =				\
					$(SRCS_DIR)/main.c \
					$(SRCS_DIR)/utils_0_main.c \
					$(SRCS_DIR)/utils_1_parsing.c \
					$(SRCS_DIR)/utils_2_init_set_check.c \
					$(SRCS_DIR)/utils_3_algo.c \
					$(SRCS_DIR)/utils_4_large_set_algo.c \
					$(SRCS_DIR)/utils_5_list_utils.c \
					$(SRCS_DIR)/utils_6_instructions.c \
					$(SRCS_DIR)/utils_7_instruction_list.c \
					$(SRCS_DIR)/utils_8_list_mgt_1.c \
					$(SRCS_DIR)/utils_9_list_mgt_2.c\

OBJS				= $(SRCS:.c=.o)
INCLUDES			= -I $(LIBFT_DIR) -I $(HEAD_DIR)
CFLAGS 				= -Wall -Wextra -Werror $(INCLUDES)
GREEN 				= \033[01;32m
RESET 				= \033[00m

%.o :				%.c
					@gcc -c -g $(CFLAGS) $< -o $@
$(NAME):			$(OBJS)
					@make -C $(LIBFT_DIR)
					@gcc -g $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)
					@echo "$(GREEN)Successfully compiled $(RESET)"

all:				$(NAME)
clean:				
					@make clean -C $(LIBFT_DIR)
					@rm -f $(OBJS)
					@echo "$(GREEN)Successfully cleaned $(RESET)"
fclean: 			clean
					@make fclean -C $(LIBFT_DIR)
					@rm -f $(NAME)
					@echo "$(GREEN)Successfully f-cleaned $(RESET)"
re: 				fclean all
.PHONY: 			all clean fclean re
