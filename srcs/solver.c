/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 01:20:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/20 19:30:20 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			movex(t_field *tetromino)
{
	bf_moveright(tetromino, 1);
	return (0);
}

int			movey(t_field *tetromino)
{
	bf_moveleft(tetromino, tetromino->x);
	bf_movedown(tetromino, 1);
	return (0);
}

int			move(t_field *board, t_field *tetromino)
{
	if (tetromino->bh > board->h)
		return (0);
	while ((size_t)tetromino->y <= board->h - tetromino->bh)
	{
		while ((size_t)tetromino->x <= board->w - tetromino->bw)
		{
			if (bf_overlap(board, tetromino))
				return (1);
			movex(tetromino);
		}
		movey(tetromino);
	}
	return (0);
}

int			solve_board(t_field *board, t_dlist *input, t_dlist **output)
{
	t_field		*tetromino;
	t_field		*tmp;
	t_dlist		*ref;

	if (!input)
		return (1);
	tetromino = bf_new(board->w, board->h);
	tmp = input->content;
	bf_fieldplus(tetromino, tmp);
	tetromino->bh = tmp->bh;
	tetromino->bw = tmp->bw;
	if (*output)
	{
		ref = dl_get_last(output);
		tmp = ref->content;
		bf_moveright(tetromino, tmp->x);
		bf_movedown(tetromino, tmp->y);
	}
	if (move(board, tetromino))
	{
		bf_fieldplus(board, tetromino);
		dl_putlast(output, tetromino);
		if (solve_board(board, input->next, output))
			return (1);
		bf_fieldminus(board, tetromino);
		dl_del_last(output);
	}
	return (0);
}

void		solver(t_program *Program)
{
	t_dlist		*input;

	input = Program->input;
	while (!(solve_board(Program->board, Program->input, &Program->output)))
	{
		bf_del(Program->board);
		Program->input = input;
		Program->board = bf_new(Program->board->h + 1, Program->board->w + 1);
	}
	return (render_output(Program));
}
