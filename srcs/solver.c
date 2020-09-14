
#include "fillit.h"

void		bf_clear(t_field *field)
{
	size_t	i;

	i = 0;
	while (i < field->h)
	{
		field->row[i] = 0;
		i++;
	}
}

t_field		*bf_dup(t_field *src)
{
	t_field		*dest;
	size_t		i;

	i = 0;
	dest = bf_new(src->w, src->h);
	while (i < src->h)
	{
		dest->row[i] = src->row[i];
		i++;
	}
	return (dest);
}

t_dlist			*dl_get_last(t_dlist *list)
{
	while(list->next)
		list = list->next;
	return (list);
}

int				solve_map(t_program *Program, t_field *tetromino, size_t x, size_t y)
{
	t_field		*tmp_fld;

	if (!Program->input->next)
		return (1);
	bf_fieldplus(tetromino, Program->input->content);
	tetromino->h = Program->board->h;
	tetromino->w = Program->board->w;
	while (y <= Program->board->h)
	{
		while (x <= Program->board->w)
		{
			if (bf_overlap(Program->board, tetromino))
			{
				bf_fieldplus(Program->board, tetromino);
				dl_putlast(&Program->output, tetromino);
				Program->input = Program->input->next;
				tmp_fld = Program->input->content;
				if (solve_map(Program, tetromino, tmp_fld->w, tmp_fld->h))
					return (1);
				else
					bf_fieldminus(Program->board, tetromino);
			}
			else
			{
				bf_moveright(tetromino, 1);
				x++;
			}
		}
		bf_moveleft(tetromino, x);
		bf_movedown(tetromino);
		x = 0;
		y++;
	}
	return (0);
}

void		solver(t_program *Program)
{
	t_field		*tmp;
	t_field		*init_output;

	tmp = Program->input->content;
	init_output = bf_dup(Program->board);
	while ((solve_map(Program, init_output, tmp->w, tmp->h) == 0))
	{
		bf_clear(Program->board);
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
