/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 01:20:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/24 02:34:59 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			place(t_field *board, t_field *tetromino, size_t x, size_t y)
{
	bf_moveright(tetromino, x);
	bf_movedown(tetromino, y);
	if (bf_overlap(board, tetromino))
		return (1);
	bf_moveleft(tetromino, x);
	bf_moveup(tetromino, y);
	return (0);
}

int			solve_board(t_field *board, t_dlist *input, t_dlist **output)
{
	t_field		*tetromino;
	size_t		x;
	size_t		y;

	if (!input)
		return (1);
	tetromino = bf_new(board->w, board->h);
	bf_fieldplus(tetromino, input->content);
	y = 0;
	if (tetromino->bh > board->h || tetromino->bw > board->w)
		return (0);
	while (y <= board->h - tetromino->bh)
	{
		x = 0;
		while (x <= board->w - tetromino->bw)
		{
			if (place(board, tetromino, x, y))
			{
				bf_fieldplus(board, tetromino);
				dl_putlast(output, tetromino);
				if (solve_board(board, input->next, output))
					return (1);
				bf_fieldminus(board, tetromino);
				bf_moveleft(tetromino, x);
				bf_moveup(tetromino, y);
				dl_del_last(output);
			}
			x++;
		}
		y++;
	}
	free(tetromino);
	return (0);
}

void		solver(t_program *program)
{
	t_dlist		*input;

	input = program->input;
	while (!(solve_board(program->board, program->input, &program->output)))
	{
		bf_del(program->board);
		program->input = input;
		program->board = bf_new(program->board->h + 1, program->board->w + 1);
	}
	return (render_output(program));
}
