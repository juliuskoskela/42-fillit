# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/26 12:48:50 by jkoskela          #+#    #+#              #
#    Updated: 2020/09/15 01:11:12 by jkoskela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = bitlib.a

SRC = bf_column.c \
	  	bf_fill.c \
		bf_init.c \
		bf_init.c \
		bf_moveleft.c \
		bf_moveright.c \
		bf_movedown.c \
		bf_moveup.c \
		bf_print.c \
		checkbit.c \
		highest_one.c \
		lowest_one.c \
		printbits.c \
		readbits.c \
		b.c \
		bf_cmp.c \
		bf_new.c \
		bf_fieldsize.c \
		bf_del.c \
		bf_overlap.c \
		bf_fieldminus.c \
		bf_fieldplus.c \
		bf_dup.c \
		bf_clear.c \

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
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@echo "$(NAME) fcleaned!"
ifneq (,$(wildcard .DS_Store))
	rm -r .DS_Store
	@echo "Deleted .DS_Store in $(NAME)"
endif

re: fclean all

.PHONY: all, clean, fclean, re
