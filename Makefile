LIBFT = libft/libft.a
LIBDL = libdl/libdl.a
BITLIB = bitlib/bitlib.a
NAME = fillit
SRCS = srcs/fillit.c \
		srcs/read_input.c \
		srcs/val_blocks.c \
		srcs/val_input.c \

OBJS = $(SRCS:.c=.o)
DEBUG = $(NAME).dSYM

.PHONY: all clean fclean re

all: $(NAME)

clean:
	make -C libft clean
	make -C libdl clean
	make -C bitlib clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	make -C libdl fclean
	make -C bitlib fclean
	rm -f $(NAME)
	rm -r $(DEBUG)

re: fclean all

$(NAME): $(OBJS)
	make -C libft
	make -C libdl
	make -C bitlib
	gcc -g -Wall -Wextra -Werror $(SRCS) $(LIBFT) $(BITLIB) $(LIBDL) -o $(NAME)
