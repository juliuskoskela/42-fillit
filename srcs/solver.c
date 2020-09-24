/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 01:20:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/25 01:23:19 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include "fillit.h"

int			place(t_field *brd, t_field *tet, size_t x, size_t y)
{
	bf_moveright(tet, x);
	bf_movedown(tet, y);
	if (bf_overlap(brd, tet))
		return (1);
	bf_moveleft(tet, x);
	bf_moveup(tet, y);
	return (0);
}

int			prep_tet(t_field **brd, t_dlist **in, t_dlist **out, t_field **tet)
{
	t_dlist		*ref;
	t_field		*tmp;

	*tet = bf_new((*brd)->w, (*brd)->h);
	tmp = (*in)->content;
	(*tet)->bw = tmp->w;
	(*tet)->bh = tmp->h;
	if ((*brd)->h < tmp->h || (*brd)->w < tmp->w)
		return (0);
	bf_fieldplus(*tet, (*in)->content);
	if (*out)
	{
		ref = *out;
		while (ref->next)
			ref = ref->next;
		tmp = ref->content;
		bf_moveright(*tet, tmp->x);
		bf_movedown(*tet, tmp->y);
	}
	return (1);
}

int			solve_board(t_field *brd, t_dlist *in, t_dlist **out, t_field *tet)
{
	size_t		x;
	size_t		y;

	if (!in)
		return (1);
	if (!(prep_tet(&brd, &in, out, &tet)))
		return (0);
	y = 0;
	while (y <= brd->h - tet->bh)
	{
		x = 0;
		while (x <= brd->w - tet->bw)
		{
			if (place(brd, tet, x, y))
			{
				bf_fieldplus(brd, tet);
				if (solve_board(brd, in->next, out, tet))
				{
					dl_putlast(out, tet);
					return (1);
				}
				bf_fieldminus(brd, tet);
				bf_moveleft(tet, x);
				bf_moveup(tet, y);
			}
			x++;
		}
		y++;
	}
	bf_del(tet);
	return (0);
}

void		solver(t_program *program)
{
	t_dlist		*input;
	t_field		*tetromino;

	input = program->input;
	tetromino = program->input->content;
	while (!(solve_board(program->board, program->input, &program->output,\
														tetromino)))
	{
		bf_del(program->board);
		program->board = bf_new(program->board->h + 1, program->board->w + 1);
	}
	render_output(program);
}
