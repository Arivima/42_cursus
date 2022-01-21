NAME				= pipex

LIB_DIR				= ./lib
LIBFT_DIR			= $(LIB_DIR)/libft
LIBFT_A				= $(LIBFT_DIR)/libft.a
PRINTF_DIR			= $(LIB_DIR)/ft_printf
PRINTF_A			= $(PRINTF_DIR)/libftprintf.a
LIB_A				= $(LIBFT_A) $(PRINTF_A) 

HEAD_DIR			= ./include

FILES				= \
						main.c\
						error.c\
						utils.c\


SRCS_DIR			=	./srcs
SRCS				= $(addprefix $(SRCS_DIR)/,$(FILES))

OBJS_DIR			=	./objs
OBJS				= $(patsubst $(SRCS_DIR)%,$(OBJS_DIR)%,$(SRCS:.c=.o))

INCLUDES			= -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I $(HEAD_DIR)
CFLAGS 				= -Wall -Wextra -Werror $(INCLUDES) -g

GREEN 				= \033[01;32m
RESET 				= \033[00m

all:				$(NAME)

$(NAME):			libraries $(LIB_A) $(OBJS) 
					@gcc -g $(CFLAGS) $(OBJS) $(LIB_A) -o $(NAME)
					@echo "$(GREEN)$(NAME) successfully compiled $(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
					@mkdir -p $(@D)
					@gcc -c -g $(CFLAGS) $< -o $@

$(OBJS): 			| $(OBJS_DIR)

$(OBJS_DIR):
					@mkdir $(OBJS_DIR)

libraries:			
					@printf "Making libft..." && make -C $(LIBFT_DIR)
					@printf "Making printf..." && make -C $(PRINTF_DIR)

clean:				
					@make clean -C $(LIBFT_DIR)
					@make clean -C $(PRINTF_DIR)
					@rm -f $(OBJS)
					@echo "$(GREEN)Successfully cleaned objects  - $(NAME)$(RESET)"

fclean: 			clean
					@make fclean -C $(LIBFT_DIR)
					@make fclean -C $(PRINTF_DIR)
					@rm -f $(OBJS)
					@rm -f $(NAME)
					@rm -rf $(OBJS_DIR)
					@echo "$(GREEN)Successfully forced cleaned - $(NAME)$(RESET)"

bis:				
					@rm -f $(OBJS)
					@rm -f $(NAME)
					@rm -rf $(OBJS_DIR)
					@echo "$(GREEN)Successfully cleaned binary and objects  - $(NAME)$(RESET)"
					@make

run:				bis
					./pipex file1 "grep Harry" "wc -l" file2 
					cat file2
					./pipex file1 "ls -l" "wc -l" file2 
					cat file2
					@echo "$(GREEN)Successfully executed $(NAME)$(RESET)"

re: 				fclean all
.PHONY: 			all clean fclean re libraries bis run
