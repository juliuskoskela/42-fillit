# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 00:14:29 by jkoskela          #+#    #+#              #
#    Updated: 2020/09/24 03:11:29 by jkoskela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isupper.c \
		ft_islower.c \
		ft_iswspace.c \
		ft_itoa.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strndup.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstnew.c \
		ft_lstmap.c \
		ft_sizeofint.c \
		ft_strrev.c \
		ft_sign.c \
		ft_calloc.c \
		ft_strlcpy.c \
		ft_atoi_base.c \
		ft_atof.c \
		ft_strcdup.c \
		ft_lentoc.c \
		ft_strcsub.c \
		ft_gnl.c \
		ft_sqrt.c \
		ft_log2_64.c \
		error.c \
		bf_column.c \
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
		bitoa.c \
		dl_len.c \
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
		dl_del_list.c \

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
