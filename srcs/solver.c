// **************************************************************************
//
//                                                        :::      ::::::::
//   solver.c                                           :+:      :+:    :+:
//                                                    +:+ +:+         +:+
//   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+
//                                                +#+#+#+#+#+   +#+
//   Created: 2020/09/07 20:20:04 by jkoskela          #+#    #+#
//   Updated: 2020/09/09 00:30:51 by jkoskela         ###   ########.fr
//
// **************************************************************************

#include "fillit.h"

t_field		*fitblock(t_field *input, t_field *board, size_t x, size_t y)
{
	t_field		*newblock;

	newblock = bf_new(board->w, board->h);
	bf_fieldplus(newblock, input);			// Copy base input to newblock;
	while (y < board->h - input->h)
	{
		if (x < board->w - input->w)
		{
			if (!(bf_overlap(board, newblock)))
			{
				bf_moveright(newblock, 1);
				x++;
			}
			else
				return (newblock);
		}
		else
		{
			bf_moveleft(newblock, x);
			bf_movedown(&newblock, 1);
			x = 0;
			y++;
		}
	}
	return (NULL);
}

void		solver(t_program *PROGRAM, t_dlist *tmp, t_dlist *output)
{											// tmp takes pointer to PROGRAM->INPUT, output is NULL
	t_field		*block_output;
	t_dlist		*n;

	block_output = fitblock(tmp->content, PROGRAM->BOARD, 0, 0);

	if (!tmp->next && block_output != NULL)	// 1. *Base Case* If block fits the board and is last block.
	{
		dl_putlast(&output, block_output);					// Store last block in output list.
		/* render_output(output, PROGRAM->BLOCK_COUNT);*/	// Real printout.
		bf_print(PROGRAM->BOARD);							// Test printout.
		return ;											// End recursion.
	}
	if (block_output != NULL)				// 2. If block fits the board.
	{
		bf_fieldplus(PROGRAM->BOARD, block_output);			// Update board with block.
		dl_putlast(&output, block_output);					// Store block in output.
		solver(PROGRAM, tmp->next, output);					// Try next block on the board.
	}
	else if (!tmp->next)					// 3. If block doesn't fit and is last block.
	{
		tmp = PROGRAM->INPUT;								// Reset tmp to original head of input list and increase board size.
		PROGRAM->BOARD->h = PROGRAM->BOARD->h + 1;
		PROGRAM->BOARD->w = PROGRAM->BOARD->w + 1;
		PROGRAM->BOARD = bf_new(PROGRAM->BOARD->h , PROGRAM->BOARD->w);
		while (output)										// Delete output list
		{
			dl_del_node(&output, output->content);
			output = output->next;
		}
		solver(PROGRAM, PROGRAM->INPUT, output);			// Reset tmp to PROGRAM->INPUT at call.
	}
	else if (tmp->next)						// 4. If block doesn't fit, but isn't last block
	{
		if (output)
		{
			n = output;										// Put n to last block in output.
			while (n->next)									// Search for last block in output.
				n = n->next;
			bf_fieldminus(PROGRAM->BOARD, n->content);		// Remove last block in output from board
			dl_del_last(&output); 							// Remove last block in output from output
			solver(PROGRAM, tmp->next, output);				// Return and set tmp pointer to next block from previous iteration.
		}
	}
}
