LIBFT = libft/libft.a

BITLIB = bitlib/bitlib.a

NAME = fillit

SRCS = fillit.c

OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	make -C libft
	gcc -g -Wall -Wextra -Werror $(SRCS) $(LIBFT) $(BITLIB) -o $(NAME)
