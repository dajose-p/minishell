# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danjose- <danjose-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/26 00:00:00 by danjose-          #+#    #+#              #
#    Updated: 2026/01/26 20:22:19 by danjose-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================ #
#                                   PROGRAM                                    #
# ============================================================================ #

NAME        := minishell

# ============================================================================ #
#                                  COMPILER                                    #
# ============================================================================ #

CC          := cc
CFLAGS      := -Wall -Wextra -Werror -g
LDFLAGS     := -lreadline

# ============================================================================ #
#                                 DIRECTORIES                                  #
# ============================================================================ #

SRC_DIR     := srcs
BUILTIN_DIR := builtins
OBJ_DIR     := objs
LIBFT_DIR   := libft

# ============================================================================ #
#                                   COLORS                                     #
# ============================================================================ #

GREEN       := \033[0;32m
YELLOW      := \033[0;33m
RED         := \033[0;31m
CYAN        := \033[0;36m
BLUE        := \033[0;34m
RESET       := \033[0m

# ============================================================================ #
#                                SOURCE FILES                                  #
# ============================================================================ #

# Archivos en srcs/
SRCS_MAIN   := main.c \
               checks.c \
               lst_ops.c

# Archivos en builtins/
SRCS_BUILTIN := echo.c \
                pwd.c \
                cd.c \
                exit.c \
                main_func.c

# Construcción de rutas completas
SRC_FILES    := $(addprefix $(SRC_DIR)/, $(SRCS_MAIN))
BUILTIN_FILES:= $(addprefix $(BUILTIN_DIR)/, $(SRCS_BUILTIN))
ALL_SRCS     := $(SRC_FILES) $(BUILTIN_FILES)

# ============================================================================ #
#                                OBJECT FILES                                  #
# ============================================================================ #

OBJS        := $(addprefix $(OBJ_DIR)/, $(notdir $(ALL_SRCS:.c=.o)))

# ============================================================================ #
#                                  LIBRARIES                                   #
# ============================================================================ #

LIBFT       := $(LIBFT_DIR)/libft.a

# ============================================================================ #
#                                   INCLUDES                                   #
# ============================================================================ #

INCLUDES    := -I$(LIBFT_DIR) -I. -I$(BUILTIN_DIR)

# ============================================================================ #
#                               SEARCH PATHS                                   #
# ============================================================================ #

VPATH       := $(SRC_DIR):$(BUILTIN_DIR)

# ============================================================================ #
#                                PROGRESS BAR                                  #
# ============================================================================ #

TOTAL       := $(words $(ALL_SRCS))
CURRENT     := 0

# ============================================================================ #
#                                   RULES                                      #
# ============================================================================ #

all: banner $(NAME)
	@echo "$(GREEN)╔══════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║     ✓ Minishell compiled!            ║$(RESET)"
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

# Regla de compilación usando VPATH
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
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
	@norminette $(SRC_DIR) $(BUILTIN_DIR) $(LIBFT_DIR) minishell.h builtins/builtins.h || true

help:
	@echo "$(CYAN)Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)      - Build the project (default)"
	@echo "  $(GREEN)clean$(RESET)    - Remove object files"
	@echo "  $(GREEN)fclean$(RESET)   - Remove object files and binaries"
	@echo "  $(GREEN)re$(RESET)       - Rebuild everything"
	@echo "  $(GREEN)run$(RESET)      - Build and run the program"
	@echo "  $(GREEN)debug$(RESET)    - Build with debug flags and sanitizer"
	@echo "  $(GREEN)norm$(RESET)     - Check norminette compliance"
	@echo "  $(GREEN)show$(RESET)     - Show all variables (for debugging)"
	@echo "  $(GREEN)help$(RESET)     - Show this help message"

# Debug: muestra todas las variables (útil para verificar rutas)
show:
	@echo "$(CYAN)=== DIRECTORIES ===$(RESET)"
	@echo "SRC_DIR:     $(SRC_DIR)"
	@echo "BUILTIN_DIR: $(BUILTIN_DIR)"
	@echo "OBJ_DIR:     $(OBJ_DIR)"
	@echo "LIBFT_DIR:   $(LIBFT_DIR)"
	@echo ""
	@echo "$(CYAN)=== SOURCE FILES ===$(RESET)"
	@echo "SRCS_MAIN:"
	@echo "  $(SRCS_MAIN)" | tr ' ' '\n' | sed 's/^/  /'
	@echo "SRCS_BUILTIN:"
	@echo "  $(SRCS_BUILTIN)" | tr ' ' '\n' | sed 's/^/  /'
	@echo ""
	@echo "$(CYAN)=== FULL PATHS ===$(RESET)"
	@echo "SRC_FILES:"
	@echo "  $(SRC_FILES)" | tr ' ' '\n' | sed 's/^/  /'
	@echo "BUILTIN_FILES:"
	@echo "  $(BUILTIN_FILES)" | tr ' ' '\n' | sed 's/^/  /'
	@echo ""
	@echo "$(CYAN)=== OBJECT FILES ===$(RESET)"
	@echo "OBJS:"
	@echo "  $(OBJS)" | tr ' ' '\n' | sed 's/^/  /'
	@echo ""
	@echo "$(CYAN)=== INCLUDES ===$(RESET)"
	@echo "$(INCLUDES)"
	@echo ""
	@echo "$(CYAN)=== VPATH ===$(RESET)"
	@echo "$(VPATH)"

.PHONY: all clean fclean re run debug norm help banner show