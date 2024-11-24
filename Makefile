NAME = MINISHELL
BLUE = \033[0;34m
RED = \033[0;31m
RESET = \033[0m
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -Iincludes -Ilibft
SRCDIR = srcs
OBJDIR = objs
LIBFTDIR = includes/libft
SRCS = $(SRCDIR)/minishell.c \
       $(SRCDIR)/message_manage.c \
       $(SRCDIR)/check_function.c \
       $(SRCDIR)/tokenize.c \
       $(SRCDIR)/tokenize_utils.c \
       $(SRCDIR)/minishell_utils_1.c
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)
	
$(NAME): $(LIBFT) $(OBJS)
	@echo "$(BLUE)Generando el ejecutable $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -lreadline
	@echo "$(BLUE)MINISHEL COMPILED😎$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBFT):
	@make -C $(LIBFTDIR)

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFTDIR) fclean

re: clean all

.PHONY: all clean fclean re
