# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 12:48:50 by jkoskela          #+#    #+#              #
#    Updated: 2020/09/21 14:23:07 by jkoskela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = libdl.a

SRC = dl_len.c \
		dl_putfirst.c \
		dl_putlast.c \
		dl_putbefore.c \
		dl_putafter.c \
		dl_print.c \
		dl_del_node.c \
		dl_del_node_at.c \
		dl_del_last.c \
		dl_rotate.c \
		dl_get_last.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) created!"


%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(NAME) cleaned!"

fclean:
	@rm -f $(NAME)
	@rm -f $(OBJ)
	@echo "$(NAME) fcleaned!"
ifneq (,$(wildcard .DS_Store))
	rm -r .DS_Store
	@echo "Deleted .DS_Store in $(NAME)"
endif

re: fclean all

.PHONY: all, clean, fclean, re
