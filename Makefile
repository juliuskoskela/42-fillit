LIBNAME = libft/libft.a

NAME = fillit

SRCS = 		srcs/ft_solver.c\
			srcs/ft_printing.c\
			srcs/ft_listmaker.c\
			srcs/ft_is_valid.c\
			srcs/ft_strmaker.c\
			srcs/main.c\

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
	gcc -Wall -Wextra -Werror $(SRCS) $(LIBNAME) -o $(NAME)
