/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:07:04 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/11 16:35:21 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_field		*fitblock(t_field **input, t_field **board, size_t x, size_t y)
{
	t_field		*newblock;

	if ((*board)->w <= (*input)->w || (*board)->h <= (*input)->h)
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

void		dl_del_list(t_dlist **ref)
{
	t_dlist		*n;
	t_field		*tmp;
	t_dlist		*tmp2;

	tmp2 = (*ref);
	while (tmp2)
	{
		tmp = tmp2->content;
		bf_del(&tmp);
		n = tmp2;
		tmp2 = tmp2->next;
		dl_del_node(&n, n);
	}
}

t_field		*fitblock_list(t_dlist **input, t_field **board)
{
	t_field		*ret;
	t_dlist		*tmp;

	tmp = *input;
	while (tmp)
	{
		ret = tmp->content;
		if ((ret = fitblock(&ret, board, 0, 0)) != NULL)
			return (ret);
		tmp = tmp->next;
	}
	return (NULL);
}

void		solver(t_program *PROGRAM, t_dlist *input, t_dlist *output, size_t i)
{
	t_field		*ret;
	t_dlist		*tmp;
	size_t		bcnt = 0;

	if (i == PROGRAM->BLOCK_COUNT)
	{
		bcnt = dl_len(output);
		printf("Output count at exit: %zu\n\n", bcnt);
		printf("Board at exit:\n\n");
		bf_print(PROGRAM->BOARD);
		printf("\nOutput list at exit:\n\n");
		field_list_print(output);
		ERROR("\nFinished!\n");
		return ;
	}
	if ((ret = fitblock_list(&input, &PROGRAM->BOARD)))
	{
		dl_putlast(&output, ret);
		bf_fieldplus(PROGRAM->BOARD, ret);
		solver(PROGRAM, input->next, output, i + 1);
	}
	else if (i > 0)
	{
		tmp = output;
		while (tmp->next)
			tmp = tmp->next;
		bf_fieldminus(PROGRAM->BOARD, tmp->content);
		dl_del_last(&output);
		solver(PROGRAM, input, output, i - 1);
	}
	else
	{
		PROGRAM->BOARD->h++;
		PROGRAM->BOARD->w++;
		PROGRAM->BOARD = bf_new(PROGRAM->BOARD->w, PROGRAM->BOARD->h);
		solver(PROGRAM, PROGRAM->INPUT, output, 0);
	}
}
