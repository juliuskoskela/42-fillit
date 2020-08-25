# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/24 16:24:31 by esukava           #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2020/08/25 19:19:43 by esukava          ###   ########.fr        #
=======
#    Updated: 2020/08/25 13:17:32 by jkoskela         ###   ########.fr        #
>>>>>>> 46c14b5f186929cf409bc22b55c1815f0fba45bf
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
<<<<<<< HEAD
		solver.c \
=======
>>>>>>> 46c14b5f186929cf409bc22b55c1815f0fba45bf
		b.c \

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
