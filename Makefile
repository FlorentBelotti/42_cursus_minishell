# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbelotti <marvin@42perpignan.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 11:47:53 by fbelotti          #+#    #+#              #
#    Updated: 2024/06/20 11:52:03 by fbelotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
AUTHOR1 = ZomDev3343
AUTHOR2 = Florent Belotti

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I./Includes -I./Includes/zom_libft -I/opt/homebrew/Cellar/readline/8.2.10/include
LIBS = ./Includes/zom_libft/libft.a -L/opt/homebrew/Cellar/readline/8.2.10/lib -lreadline -lhistory

SRCDIR = Src
OBJDIR = obj

SRC = $(shell find $(SRCDIR) -name \*.c -type f -print)
OBJ = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

DEPS = $(OBJ:.o=.d)

all: announce intro libft $(NAME)

announce:
	@echo "\n==================================="
	@echo "Project: $(NAME)\n"
	@echo "Parsing: $(AUTHOR1)"
	@echo "Execution: $(AUTHOR2)"
	@echo "===================================\n"

intro:
	@echo "Starting the build process...\n"

$(NAME): $(OBJ)
	@echo "\nminishell:	Creating library..."
	@$(MAKE) -C ./Includes/zom_libft > /dev/null
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) $(INCLUDES) -o $@
	@echo "minishell:	Executable $@ created."

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@echo "minishell: Src: compiling file $@"
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -c $< -o $@

libft:
	@$(MAKE) -C ./Includes/zom_libft > /dev/null

-include $(DEPS)

clean:
	@$(RM) $(OBJ)
	@$(MAKE) -C ./Includes/zom_libft clean > /dev/null
	@echo "Cleaned."

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C ./Includes/zom_libft fclean > /dev/null
	@echo "Fully cleaned."

re: fclean all

debug: CFLAGS += $(DEBUG_FLAGS)
debug: re

.PHONY: all clean fclean re libft announce intro
