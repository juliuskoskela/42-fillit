LIBFT = libft/libft.a

LIBDL = libdl/libdl.a

BITLIB = bitlib/bitlib.a

NAME = fillit

SRCS = fillit.c

OBJS = $(SRCS:.c=.o)

DEBUG = $(NAME).dSYM

.PHONY: all clean fclean re

all: $(NAME)

clean:
	make -C libft clean
	make -C libdl clean
	make -C bitlib clean
	rm -f $(OBJS)
	rm -r $(DEBUG)

fclean: clean
	make -C libft fclean
	make -C libdl clean
	make -C bitlib clean
	rm -f $(NAME)
	rm -r $(DEBUG)

re: fclean all

$(NAME): $(OBJS)
	make -C libft
	make -C libdl
	make -C bitlib
	gcc -g -Wall -Wextra -Werror $(SRCS) $(LIBFT) $(BITLIB) $(LIBDL) -o $(NAME)
