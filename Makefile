LIBFT = libft/libft.a
NAME = fillit
SRCS = srcs/fillit.c \
		srcs/read_input.c \
		srcs/val_blocks.c \
		srcs/normalize_block.c \
		srcs/solver.c \
		srcs/render_output.c \
		srcs/ref_blocks_list.c \

OBJS = $(SRCS:.c=.o)
DEBUG = $(NAME).dSYM

.PHONY: all clean fclean re

all: $(NAME)

clean:
ifneq (,$(wildcard $(NAME).dSYM))
	@rm -r $(DEBUG)
	@echo "Deleted $(NAME).dSYM in $(NAME)"
endif
	@make -C libft clean
	@rm -f $(OBJS)
	@echo "Deleted all .o files!"

fclean:
	@make -C libft fclean
	@rm -f $(OBJS)
	@rm -f $(NAME)
	rm -rf
	@echo "Deleted all .o files!"
ifneq (,$(wildcard .DS_Store))
	@rm -r .DS_Store
	@echo "Deleted .DS_Store in $(NAME)"
endif
ifneq (,$(wildcard $(NAME).dSYM))
	@rm -r $(DEBUG)
	@echo "Deleted $(NAME).dSYM in $(NAME)"
endif

re: fclean all

l:
	@make -C libft
d:
	@gcc -g -Wall -Wextra -Werror $(SRCS) $(LIBFT) -o $(NAME)
	@echo "Lldb debug folder"
	@echo "Compilation of $(NAME) successful!"
	time ./fillit filetest.txt

$(NAME): $(OBJS)
	@make -C libft
	@gcc -Wall -Wextra -Werror $^ $(LIBFT) -o $(NAME)
	@echo "Compilation of $(NAME) successful!"

%.o: %.c
	@gcc -c -Wall -Wextra -Werror -o $@ $<