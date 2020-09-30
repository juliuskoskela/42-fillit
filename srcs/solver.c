/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 01:20:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/30 18:02:58 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			place(t_field *brd, t_field *tet, size_t x, size_t y)
{
	bf_moveright(tet, x);
	bf_movedown(tet, y);
	if (bf_overlap(brd, tet))
		return (1);
	bf_moveleft(tet, x);
	bf_moveup(tet, y);
	return (0);
}

static int			prep_tet(t_field *brd, t_field *tmp, t_field **tet)
{
	*tet = bf_new(brd->w, brd->h);
	(*tet)->bw = tmp->w;
	(*tet)->bh = tmp->h;
	if (brd->h < tmp->h || brd->w < tmp->w)
		return (0);
	bf_fieldplus(*tet, tmp);
	return (1);
}

static void		reset(t_field *board, t_field *tet, size_t x, size_t y)
{
	bf_fieldminus(board, tet);
	bf_moveleft(tet, x);
	bf_moveup(tet, y);
}

static int			solve_board(t_program *program, t_field *tet, t_dlist *in, int y)
{
	int x;

	if (!in)
		return (1);
	if (!(prep_tet(program->board, in->content, &tet)))
		return (0);
	while (y++ < (int)(program->board->h - tet->bh))
	{
		x = -1;
		while (x++ < (int)(program->board->w - tet->bw))
		{
			if (place(program->board, tet, x, y))
			{
				bf_fieldplus(program->board, tet);
				if (solve_board(program, tet, in->next, -1))
				{
					dl_putlast(&program->output, tet);
					return (1);
				}
				reset(program->board, tet, x, y);
			}
		}
	}
	bf_del(tet);
	return (0);
}

void		solver(t_program *program)
{
	while (!(solve_board(program, NULL, program->input, -1)))
	{
		program->board->h++;
		program->board->w++;
		bf_clear(program->board);
	}
	render_output(program);
}
