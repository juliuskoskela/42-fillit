
#include "fillit.h"

t_field		*fitblock(t_field **board, t_field **input, size_t x, size_t y)
{
	t_field		*newblock;

	if ((*board)->w < (*input)->w || (*board)->h < (*input)->h)
		return (NULL);
	newblock = bf_new((*board)->w, (*board)->h);
	bf_fieldplus(newblock, *input);
	while (y <= (*board)->h - (*input)->h)
	{
		while (x <= (*board)->w - (*input)->w)
		{
			if (!(bf_overlap(*board, newblock)))
			{
				bf_moveright(newblock, 1);
				x++;
			}
			else
				return (newblock);
		}
		bf_moveleft(newblock, x);
		bf_movedown(&newblock, 1);
		x = 0;
		y++;
	}
	return (NULL);
}

int		solve_board(t_program *Program, size_t i)
{
	t_field		*ret;

	while (Program->input)
	{
		if (ret && i == Program->block_count)
			return (1);
		if ((ret = fitblock(&Program->board, &Program->input, 0,0)))
		{
			dl_putlast(&Program->output, ret);
			bf_fieldplus(Program->board, ret);
			Program->input = Program->input->next;
			solve_board(Program, i + 1);
		}
	}
	return (0);
}

void		solver(t_program *Program)
{
	int		ret;

	ret = solve_board(Program->board, 0);
	if (ret)
			return render_output(Program);
	Program->board->h++;
	Program->board->w++;
	solver(Program);
}




































// void		solver(t_program *Program)
// {
// 	t_field		*ret;
// 	t_dlist		*tmp;

// 	ret = Program->input->content;
// 	while ((ret = fitblock(&Program->board, &ret, 0, 0)))
// 	{
// 		dl_putlast(&Program->output, ret);
// 		bf_fieldplus(Program->board, ret);
// 		Program->input = Program->input->next;
// 		if (!Program->input->next)
// 			return render_output(Program);
// 	}
// 	if (Program->input->next)
// 	{
// 		tmp = Program->output;
// 		while (tmp->next)
// 			tmp = tmp->next;
// 		bf_fieldminus(Program->board, tmp->content);
// 		dl_del_last(&Program->output);
// 	}
// 	else
// 		Program->board = bf_new(Program->board->w + 1, Program->board->h + 1);
// 	solver(Program);
// }
































// t_field		*fitblock_list(t_field **board, t_dlist **input)
// {
// 	t_field		*ret;
// 	t_dlist		*tmp;

// 	tmp = *input;
// 	while (tmp)
// 	{
// 		ret = tmp->content;
// 		if ((ret = fitblock(board, &ret, 0, 0)) != NULL)
// 			return (ret);
// 		tmp = tmp->next;
// 	}
// 	return (NULL);
// }

// void		solver(t_program *Program)
// {
// 	t_field		*ret;
// 	t_dlist		*tmp;

// 	if (Program->steps == Program->block_count)
// 		return render_output(Program);
// 	if ((ret = fitblock_list(&Program->input, &Program->board)))
// 	{
// 		dl_putlast(&Program->output, ret);
// 		bf_fieldplus(Program->board, ret);
// 		Program->input = Program->input->next;
// 		Program->steps++;
// 	}
// 	else if (Program->steps > 0)
// 	{
// 		tmp = Program->output;
// 		while (tmp->next)
// 			tmp = tmp->next;
// 		bf_fieldminus(Program->board, tmp->content);
// 		dl_del_last(&Program->output);
// 	}
// 	else
// 	{
// 		Program->board = bf_new(Program->board->w + 1, Program->board->h + 1);
// 		dl_rotate(&Program->input, 1);
// 	}
// 	solver(Program);
// }

// void		solver(t_program *Program)
// {
// 	t_field		*ret;

// 	if (Program->input)
// 	{
// 		ret = Program->input->content;
// 		if ((ret = fitblock(&Program->board, &ret, 0, 0)))
// 		{
// 			dl_putlast(&Program->output, ret);
// 			bf_fieldplus(Program->board, ret);
// 			Program->input = Program->input->next;
// 			if (!Program->input->next)
// 				return render_output(Program);
// 		}
// 	}
// 	else
// 		Program->board = bf_new(Program->board->w + 1, Program->board->h + 1);
// 	solver(Program);
// }
