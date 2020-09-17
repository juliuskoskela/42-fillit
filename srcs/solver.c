/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 01:20:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/17 18:21:56 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			movex(t_field *board, t_field *tetromino)
{
	if (bf_overlap(board, tetromino))
		return (1);
	bf_moveright(tetromino, 1);
	return (0);
}

int			movey(t_field *board, t_field *tetromino)
{
	if (bf_overlap(board, tetromino))
		return (1);
	bf_moveleft(tetromino, tetromino->x);
	bf_movedown(tetromino, 1);
	tetromino->x = 0;
	return (0);
}

int			solve_board(t_field *board, t_dlist *input, t_dlist **output)
{
	t_field		*tetromino;

	if (!input)
		return (1);
	tetromino = bf_dup(input->content);
	tetromino->bw = tetromino->w;
	tetromino->bh = tetromino->h;
	tetromino->w = board->w;
	tetromino->h = board->h;
	while ((size_t)tetromino->y <= board->h - tetromino->bh)
		while ((size_t)tetromino->x <= board->w - tetromino->bw)
		{
			if (movex(board, tetromino) || movey(board, tetromino))
			{
				bf_fieldplus(board, tetromino);
				dl_putlast(output, tetromino);
				if (solve_board(board, input->next, output))
					return (1);
				bf_fieldminus(board, tetromino);
				dl_del_last(output);
			}
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
	return (render_output(Program));
}
