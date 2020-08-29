# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 12:48:50 by jkoskela          #+#    #+#              #
#    Updated: 2020/08/29 18:34:45 by jkoskela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = bitlib.a

SRC = bf_column.c \
	  	bf_fill.c \
		bf_init.c \
		bf_init.c \
		bf_moveleft.c \
		bf_normalize.c \
		bf_print.c \
		bf_xnormal.c \
		bf_ynormal.c \
		checkbit.c \
		highest_one.c \
		lowest_one.c \
		printbits.c \
		readbits.c \
		b.c \
		bf_cmp.c \
		bf_new.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"


%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
