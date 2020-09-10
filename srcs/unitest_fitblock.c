/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unitest_fitblock.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:16:34 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/09 17:04:39 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bitlib/bitlib.h"
#include "../libft/libft.h"
#include "../libdl/libdl.h"

t_field		*fitblock(t_field *input, t_field *board, size_t x, size_t y)
{
	t_field		*newblock;

	newblock = bf_new(board->w, board->h);
	bf_fieldplus(newblock, input);			// Copy base input to newblock;
	while (y <= board->h - input->h)
	{
		while (x <= board->w - input->w)
		{
			if (!(bf_overlap(board, newblock)))
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

int		main(void)
{
	t_field		*board;
	t_field		*input;
	t_field		*ret;

	board = bf_new(4, 4);
		board->row[0] = b("1111");
		board->row[1] = b("1111");
		board->row[2] = b("1110");
		board->row[3] = b("1110");
	input = bf_new(2, 2);
		input->row[0] = b("11");
		input->row[1] = b("11");
	ret = fitblock(input, board, 0, 0);
	bf_print(ret);
	return (0);
}
