/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 23:55:17 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/29 18:01:07 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib/bitlib.h"
#include "libft/libft.h"
#include "libdl/libdl.h"

typedef struct		s_program
{
	char			*FILE;
	char			ONE;
	t_dlist			*BLOCKS_REF;
	t_dlist			*INPUT;
	t_field			*BOARD;
	size_t			BLOCK_COUNT;
	int				ERROR;
}					t_program;

t_field			*newblock(size_t w, size_t h)
{
	t_field		*newblock;

	newblock = (t_field *)malloc(sizeof(t_field));
	newblock->row = bf_init(h);
	newblock->w = w;
	newblock->h = h;
	return (newblock);
}

t_dlist			*read_input(char *file, char one)
{
	char		*line;
	t_dlist		*head;
	t_field		*block;
	int			r;
	int			fd;
	size_t		i;

	i = 0;
	head = NULL;
	fd = open(file, O_RDONLY);
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
		else
		{
			block->row[i] = readbits(line, one, block->w);
			free(line);
			i++;
		}
	}
	close(fd);
	dl_del_last(&head);
	return (head);
}

int				val_blocks(t_dlist *input, t_dlist *ref)
{
	t_dlist		*pos;
	t_field		*f1;
	t_field		*f2;
	int			r;

	pos = ref;
	while (input)
	{
		f1 = input->content;
		input = input->next;
		while (pos)
		{
			f2 = pos->content;
			pos = pos->next;
			r = bf_cmp(f1, f2);
			if (r == 1)
				break ;
		}
		if (r == 0)
			return (0);
		pos = ref;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_program	*PROGRAM = (t_program *)malloc(sizeof(t_program));

	PROGRAM->ERROR = 0;
	PROGRAM->FILE = ft_strdup(argv[1]);
	PROGRAM->ONE = '#';
	PROGRAM->BOARD = newblock(2, 2);
	PROGRAM->BLOCKS_REF = read_input("txt/tetrominoes.txt", PROGRAM->ONE);
	PROGRAM->INPUT = read_input(PROGRAM->FILE, PROGRAM->ONE);
	PROGRAM->BLOCK_COUNT = dl_len(PROGRAM->INPUT);

	if (!(val_blocks(PROGRAM->INPUT, PROGRAM->BLOCKS_REF)))
	{
		printf("Blocks are not valid.\n");
		return (0);
	}
	printf("%d\n", (int)PROGRAM->BLOCK_COUNT);
	dl_print(PROGRAM->INPUT);
	argc = 0;
	return (0);
}
