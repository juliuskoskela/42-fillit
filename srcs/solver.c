
#include "fillit.h"

int			fitblock(t_field **board, t_field **tetromino, size_t x, size_t y)
{
	if (!(bf_overlap(board, tetromino)) && y <= (*board)->h)
	{
		if (x <= (*board)->w)
		{
			bf_moveright(tetromino, 1);
			x++;
		}
		else
		{
			bf_moveleft(tetromino, x);
			bf_movedown(tetromino, 1);
			x = 0;
			y++;
		}
		fitblock(board, tetromino, x, y);
	}
	if (y == (*board)->h)
		return (0);
	return (1);
}

int				solve_map(t_program *Program)
{
	t_field		*tmp;
	t_field		*tetromino;
	t_dlist		*last;

	if (!Program->input)
		return (1);
	tmp = Program->input->content;
	tetromino = bf_new(Program->board->w, Program->board->h);
	bf_fieldplus(&tetromino, &tmp);
	if (fitblock(&Program->board, &tetromino, tmp->h, tmp->w))
	{
		bf_fieldplus(&Program->board, &tetromino);
		dl_putlast(&Program->output, tetromino);
		Program->input = Program->input->next;
		solve_map(Program);
	}
	else
	{
		last = dl_get_last(Program->output);
		tmp = last->content;
		bf_fieldminus(&Program->board, &tmp);
		dl_del_last(&Program->output);
		dl_rotate(&Program->input, 1);
	}
	return (0);
}

void		solver(t_program *Program)
{
	t_dlist		*input_head;

	input_head = Program->input;
	while (!(solve_map(Program)))
	{
		bf_clear(&Program->board);
		Program->input = input_head;
		Program->board->h++;
		Program->board->w++;
	}
	return render_output(Program);
}
