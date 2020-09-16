
#include "fillit.h"

int			fitblock(t_field *board, t_field *tetromino)
{
	while ((size_t)tetromino->y <= board->h - tetromino->bh)
	{
		while ((size_t)tetromino->x <= board->w - tetromino->bw)
		{
			if (bf_overlap(board, tetromino))
				return (1);
			bf_moveright(tetromino, 1);
			tetromino->x++;
		}
		bf_moveleft(tetromino, tetromino->x);
		bf_movedown(tetromino, 1);
		tetromino->y++;
		tetromino->x = 0;
	}
	return (0);
}

int				solve_map(t_program *Program)
{
	t_field		*tetromino;
	t_field		*tmp;

	if (!Program->input->next)
		return (1);
	tmp = Program->input->content;
	tetromino = bf_new(Program->board->w, Program->board->h);
	bf_fieldplus(tetromino, Program->input->content);
	tetromino->bw = tmp->w;
	tetromino->bh = tmp->h;
	if (fitblock(Program->board, tetromino))
	{
		bf_fieldplus(Program->board, tetromino);
		dl_putlast(&Program->output, tetromino);
		Program->input = Program->input->next;
		if (solve_map(Program))
			return (1);
	}
	return (0);
}

void		solver(t_program *Program)
{
	t_dlist		*input_head;

	input_head = Program->input;
	while (!(solve_map(Program)))
	{
		Program->input = input_head;
		Program->board = bf_new(Program->board->h + 1, Program->board->w + 1);
	}
	return render_output(Program);
}
