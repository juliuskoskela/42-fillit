
#include "fillit.h"

int				movex(t_field *board, t_field *tetromino)
{
	bf_moveright(&*tetromino, 1);
	if (bf_overlap(&*board, &*tetromino));
		return(1);
	bf_moveleft(&*tetromino, 1);
	return (0);
}

int				movey(t_field **board, t_field **tetromino)
{
	bf_movedown(&*tetromino, 1);
	if (bf_overlap(&*board, &*tetromino));
		return(1);
	bf_moveup(&*tetromino, 1);
	return (0);
}


// int				solve_map(t_program *Program, t_field *tetromino, size_t x, size_t y)
// {
// 	t_field		*tmp;

// 	if (!Program->input->next)
// 		return (1);
// 	bf_fieldplus(tetromino, Program->input->content);
// 	tetromino->h = Program->board->h;
// 	tetromino->w = Program->board->w;
// 	while (
// }

int				solve_map(t_program *Program, t_field *tetromino, size_t x, size_t y)
{
	t_field		*tmp = NULL;

	if (!Program->input->next)
		return (1);
	tetromino = bf_dup(Program->input->content);
	tetromino->h = Program->board->h;
	tetromino->w = Program->board->w;
	while (y <= Program->board->h)
	{
		while (x <= Program->board->w)
		{
			if (bf_overlap(&Program->board, &tetromino))
			{
				bf_fieldplus(&Program->board, &tetromino);
				dl_putlast(&Program->output, tetromino);
				Program->input = Program->input->next;
				tmp = Program->input->content;
				if (solve_map(Program, tetromino, tmp->w, tmp->h))
					return (1);
				bf_fieldminus(&Program->board, &tetromino);
				dl_del_last(&Program->output);
			}
			bf_moveright(&tetromino, 1);
			x++;
		}
		bf_moveleft(&tetromino, x);
		bf_movedown(&tetromino, 1);
		x = 0;
		y++;
	}
	return (0);
}

void		solver(t_program *Program)
{
	t_field		*tmp;
	t_field		*tetromino;

	tmp = Program->input->content;
	tetromino = (t_field *)malloc(sizeof(t_field));
	while ((solve_map(Program, tetromino, tmp->w, tmp->h) == 0))
	{
		bf_clear(&Program->board);
		Program->board->h++;
		Program->board->w++;
	}
	return render_output(Program);
}

// int		solve_board(t_program *Program, size_t i)
// {
// 	t_field		*ret;
// 	t_dlist		*head;

// 	head = Program->input;
// 	while (Program->input)
// 	{
// 		if (ret && i == Program->tetromino_count)
// 			return (1);
// 		if ((ret = fittetromino(&Program->board, &Program->input, 0,0)))
// 		{
// 			dl_putlast(&Program->output, ret);
// 			bf_fieldplus(Program->board, ret);
// 			Program->input = Program->input->next;
// 			i++;
// 		}
// 		else
// 		{
// 			head = head->next;
// 			Program->input = head;
// 		}
// 	}
// 	return (0);
// }

// void		solver(t_program *Program)
// {
// 	int		ret;

// 	ret = solve_board(Program->board, 0);
// 	if (ret)
// 			return render_output(Program);
// 	Program->board->h++;
// 	Program->board->w++;
// 	solver(Program);
// }




































// void		solver(t_program *Program)
// {
// 	t_field		*ret;
// 	t_dlist		*tmp;

// 	ret = Program->input->content;
// 	while ((ret = fittetromino(&Program->board, &ret, 0, 0)))
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
































// t_field		*fittetromino_list(t_field **board, t_dlist **input)
// {
// 	t_field		*ret;
// 	t_dlist		*tmp;

// 	tmp = *input;
// 	while (tmp)
// 	{
// 		ret = tmp->content;
// 		if ((ret = fittetromino(board, &ret, 0, 0)) != NULL)
// 			return (ret);
// 		tmp = tmp->next;
// 	}
// 	return (NULL);
// }

// void		solver(t_program *Program)
// {
// 	t_field		*ret;
// 	t_dlist		*tmp;

// 	if (Program->steps == Program->tetromino_count)
// 		return render_output(Program);
// 	if ((ret = fittetromino_list(&Program->input, &Program->board)))
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
// 		if ((ret = fittetromino(&Program->board, &ret, 0, 0)))
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
