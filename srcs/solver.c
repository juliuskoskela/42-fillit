/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 01:20:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/17 01:22:09 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			solve_board(t_field *board, t_dlist *input, t_dlist **output)
{
	t_field		*tetromino;

	if (!input)
		return (1);
	tetromino = bf_dup(input->content);
	tetromino->w = board->w;
	tetromino->h = board->h;
	while ((size_t)tetromino->y <= board->h - tetromino->bh)
	{
		tetromino->x = 0;
		while ((size_t)tetromino->x < board->w - tetromino->bw)
		{
			if (bf_overlap(board, tetromino))
			{
				bf_fieldplus(board, tetromino);
				if (solve_board(board, input->next, output))
				{
					dl_putlast(output, tetromino);
					return (1);
				}
			}
			bf_moveright(tetromino, 1);
			tetromino->x++;
		}
		bf_moveleft(tetromino, tetromino->x);
		bf_movedown(tetromino, 1);
		tetromino->y++;
	}
	return (0);
}

void		solver(t_program *Program)
{
	t_dlist		*input_head;

	input_head = Program->input;
	while (!(solve_board(Program->board, Program->input, &Program->output)))
	{
		bf_del(Program->board);
		Program->board = bf_new(Program->board->h + 1, Program->board->w + 1);
	}
	return render_output(Program);
}
