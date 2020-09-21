/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 01:20:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/21 01:50:03 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// int			movex(t_field *tetromino)
// {
// 	bf_moveright(tetromino, 1);
// 	return (0);
// }

// int			movey(t_field *tetromino)
// {
// 	bf_moveleft(tetromino, tetromino->x);
// 	bf_movedown(tetromino, 1);
// 	return (0);
// }

// int			move(t_field *tetromino)
// {
// 	bf_moveright(tetromino, tetromino->x);
// }

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

int			solve_board(t_field *board, t_dlist *input)
{
	t_field		*tetromino;
	t_field		*tmp;
	size_t		x;
	size_t		y;

	if (!input)
		return (1);
	tetromino = bf_new(board->w, board->h);
	tmp = input->content;
	bf_fieldplus(tetromino, tmp);
	tetromino->bh = tmp->bh;
	tetromino->bw = tmp->bw;
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
				if (solve_board(board, input->next))
					return (1);
				bf_fieldminus(board, tetromino);
				bf_moveleft(tetromino, x);
				bf_moveup(tetromino, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void		solver(t_program *Program)
{
	t_dlist		*input;

	input = Program->input;
	while (!(solve_board(Program->board, Program->input)))
	{
		bf_del(Program->board);
		Program->input = input;
		Program->board = bf_new(Program->board->h + 1, Program->board->w + 1);
	}
	bf_print(Program->board);
	// return (render_output(Program));
}
