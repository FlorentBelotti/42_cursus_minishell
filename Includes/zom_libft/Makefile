SRC=ft_split.c \
	ft_split_2.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_isdigit.c \
	ft_strlen.c \
	ft_split.c \
	ft_atol.c \
	ft_error.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strjoin.c \
	ft_strnstr.c \
	ft_strchr.c \
	ft_strchr_2.c \
	ft_strdup.c \
	ft_swap.c \
	ft_array.c \
	ft_fd.c \
	ft_itoa.c \
	ft_strrepl.c \
	ft_min.c \
	ft_max.c \
	ft_putstr_fd.c \
	get_next_line_bonus_utils.c \
	get_next_line_bonus.c \
	$(PRINTF) \
	$(GNL)
OBJ= $(SRC:.c=.o)
NAME=libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o: %.c
	cc -c -Wall -Werror -Wextra -Iprintf -Ignl -g $< -o $@

clean:
	rm -rf *.o
	rm -rf */*.o

fclean: clean
	rm -rf $(NAME)

re: clean all

.PHONY: all clean fclean re
