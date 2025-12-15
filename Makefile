NAME		:= minishell
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
LDFLAGS		:= -lreadline
LIBFT_DIR	:= libft
SRC_DIR		:= srcs
OBJ_DIR		:= objs
INC_DIR		:= inc
LIBFT		:= $(LIBFT_DIR)/libft.a
INCLUDES	:= -I$(INC_DIR) -I$(LIBFT_DIR)

GREEN		:= \033[0;32m
YELLOW		:= \033[0;33m
RED			:= \033[0;31m
CYAN		:= \033[0;36m
BLUE		:= \033[0;34m
RESET		:= \033[0m

SRCS		:= main.c
SRC_FILES	:= $(addprefix $(SRC_DIR)/, $(SRCS))

OBJS		:= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
TOTAL		:= $(words $(SRCS))
CURRENT		:= 0

all: banner $(NAME)
	@echo "$(GREEN)╔══════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║     ✓ Minishell compiled!           ║$(RESET)"
	@echo "$(GREEN)╚══════════════════════════════════════╝$(RESET)"

banner:
	@echo "$(CYAN)"
	@echo "███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     "
	@echo "████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     "
	@echo "██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     "
	@echo "██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     "
	@echo "██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗"
	@echo "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝"
	@echo "$(RESET)"

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(BLUE)🔗 Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) created successfully!$(RESET)"

$(LIBFT):
	@echo "$(YELLOW)📚 Building libft...$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo "$(GREEN)✓ libft compiled!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(eval CURRENT=$(shell echo $$(($(CURRENT)+1))))
	@echo "$(CYAN)[$(CURRENT)/$(TOTAL)] Compiling $<$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(YELLOW)📁 Created $(OBJ_DIR) directory$(RESET)"

clean:
	@echo "$(RED)🧹 Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(GREEN)✓ Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(RED)🗑️  Removing binaries...$(RESET)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(GREEN)✓ All cleaned!$(RESET)"

re: fclean all

run: all
	@echo "$(BLUE)🚀 Running $(NAME)...$(RESET)"
	@./$(NAME)

debug: CFLAGS += -g3 -fsanitize=address
debug: re
	@echo "$(YELLOW)🐛 Debug build completed!$(RESET)"

norm:
	@echo "$(CYAN)📋 Running norminette...$(RESET)"
	@norminette $(SRC_DIR) $(INC_DIR) $(LIBFT_DIR) || true

help:
	@echo "$(CYAN)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)      - Build the project (default)"
	@echo "  $(GREEN)clean$(RESET)    - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)   - Remove object files and binaries"
	@echo "  $(GREEN)re$(RESET)       - Rebuild everything"
	@echo "  $(GREEN)run$(RESET)      - Build and run the program"
	@echo "  $(GREEN)debug$(RESET)    - Build with debug flags and sanitizer"
	@echo "  $(GREEN)norm$(RESET)     - Check norminette compliance"
	@echo "  $(GREEN)help$(RESET)     - Show this help message"

.PHONY: all clean fclean re run debug norm help banner
