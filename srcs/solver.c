/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:07:04 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/09 19:29:37 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_field		*fitblock(t_field **input, t_field **board, size_t x, size_t y)
{
	t_field		*newblock;

	if ((*board)->w <= (*input)->w || (*board)->h <= (*input)->h)
		return (NULL);
	newblock = bf_new((*board)->w, (*board)->h);
	bf_fieldplus(newblock, *input);			// Copy base input to newblock;
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

void		solver(t_program *PROGRAM, t_dlist *tmp, t_dlist *output)
{											// tmp takes pointer to PROGRAM->INPUT, output is NULL
	t_field		*block_output;
	t_dlist		*n;
	int			i = 1;

	block_output = tmp->content;
	block_output = fitblock(&block_output, &PROGRAM->BOARD, 0, 0);
	if (block_output && !tmp->next)					// 1. *Base Case* If block fits the board and is last block.
	{
		dl_putlast(&output, block_output);					// Store last block in output list.
		/* render_output(output, PROGRAM->BLOCK_COUNT);*/	// Real printout.
		bf_print(PROGRAM->BOARD);							// Test printout.
		while (output)
		{
			printf("b%d\n", i);
			bf_print(output->content);
			output = output->next;
			i++;
		}
		return ;											// End recursion.
	}
	if (block_output && tmp->next)					// 2. If block fits the board.
	{
		bf_fieldplus(PROGRAM->BOARD, block_output);			// Update board with block.
		dl_putlast(&output, block_output);					// Store block in output.
		solver(PROGRAM, tmp->next, output);					// Try next block on the board.
		return ;
	}
	if (!block_output && !tmp->next)				// 3. If block doesn't fit and is last block.
	{
		tmp = PROGRAM->INPUT;								// Reset tmp to original head of input list and increase board size.
		PROGRAM->BOARD->h++;
		PROGRAM->BOARD->w++;
		PROGRAM->BOARD = bf_new(PROGRAM->BOARD->h , PROGRAM->BOARD->w);
		dl_del_list(&output);
		solver(PROGRAM, PROGRAM->INPUT, output);			// Reset tmp to PROGRAM->INPUT at call.
		return ;
	}
	if 	(!block_output && tmp->next)								// 4. If block doesn't fit, but isn't last block
	{
		if (!(output))
		{	dl_rotate(&tmp, 1);
			solver(PROGRAM, tmp, output);
		n = output;										// Put n to last block in output.
		while (n->next)									// Search for last block in output.
			n = n->next;
		bf_fieldminus(PROGRAM->BOARD, n->content);		// Remove last block in output from board
		dl_del_last(&output); 							// Remove last block in output from output
		solver(PROGRAM, tmp->next, output);				// Return and set tmp pointer to next block from previous iteration.
	}
}
