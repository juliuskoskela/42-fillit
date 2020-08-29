/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 23:55:17 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/29 14:03:33 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib/bitlib.h"
#include "libft/libft.h"
#include "libdl/libdl.h"

typedef struct		s_PROGRAM
{
	char			*FILE;
	char			ONE;
	t_dlist			*BLOCKS_REF;
	t_dlist			*INPUT;
	t_field			*BOARD;
	size_t			BLOCK_COUNT;
	int				ERROR;
}					t_PROGRAM;

t_field			*newblock(size_t w, size_t h)
{
	t_field		*newblock;

	newblock = (t_field *)malloc(sizeof(t_field));
	newblock->row = bf_init(h);
	newblock->w = w;
	newblock->h = h;
	return (newblock);
}

t_dlist			*read_input(t_PROGRAM **PROGRAM)
{
	char		*line;
	t_dlist		*head = (t_dlist *)malloc(sizeof(t_dlist));
	t_field		*block;
	int			r;
	int			fd;
	size_t		i;

	i = 0;
	fd = open((*PROGRAM)->FILE, O_RDONLY);
	block = newblock(4, 4);
	dl_putfirst(&head, block);
	while ((r = ft_gnl(fd, &line)) > 0)
	{
		if (i == 4)
		{
			i = 0;
			block = newblock(4, 4);
			dl_putlast(&head, block);
		}
		if (i < 4)
		{
			block->row[i] = readbits(line, (*PROGRAM)->ONE, block->w);
			free(line);
			i++;
		}
	}
	return (head);
}

int		main(int argc, char **argv)
{
	t_PROGRAM	*PROGRAM = (t_PROGRAM *)malloc(sizeof(t_PROGRAM));

	PROGRAM->FILE = ft_strdup(argv[1]);
	PROGRAM->ONE = '#';
	PROGRAM->BLOCKS_REF = NULL;
	PROGRAM->BOARD = (t_field *)malloc(sizeof(t_field));
	PROGRAM->BOARD->row = bf_init(2);
	PROGRAM->BOARD->w = 2;
	PROGRAM->BOARD->h = 2;
	PROGRAM->BLOCK_COUNT = 0;
	PROGRAM->ERROR = 0;
	PROGRAM->INPUT = read_input(&PROGRAM);
	dl_print(PROGRAM->INPUT);
	argc = 0;
	return (0);
}
