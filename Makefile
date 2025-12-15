NAME     := minishell
CC              := cc
CFLAGS          := -g
LIBFT_DIR       := libft
LIBFT_A         := $(LIBFT_DIR)/libft.a
SRC_DIR         := srcs
OBJ_DIR         := objs
INC_DIR         := inc

GREEN   := \033[0;32m
YELLOW  := \033[0;33m
RED     := \033[0;31m
CYAN    := \033[0;36m
RESET   := \033[0m

SRCS := srcs/main.c

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	@echo "$(CYAN)[Linking client]$(RESET) $@"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)
	@echo "$(GREEN)[OK]$(RESET) Ejecutable $(NAME) creado."

$(LIBFT_A):
	@echo "$(YELLOW)[Building libft]$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJS)/%.o: $(SRCS)/%.c | $(OBJS)
	@echo "$(CYAN)[Compiling]$(RESET) $<"
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@echo "$(RED)[Cleaning objects]$(RESET)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)[Cleaning binaries]$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
