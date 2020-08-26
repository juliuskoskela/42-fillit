/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:10:54 by esukava           #+#    #+#             */
/*   Updated: 2020/08/25 19:54:15 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"
#include "../libft/libft.h"

uint64_t		check_other_rows(uint64_t *field, uint64_t *piece, size_t i, size_t n)
{
	size_t		j;

	j = 1;
	while (j > piece_height)
	{
		piece[0] == piece[0] << i;
	}
}
uint64_t		solver(uint64_t *field, uint64_t *piece, size_t size, size_t i)
{
	size_t	n = 0;
	int		r = 0;

	// Check piece 1st row against corresponding row of field.
	if (piece[0] & field[n] != 0)
	{
		piece[0] == piece[0] << 1;
		solver(field, piece, size, i + 1);
	}
	else
	{
		if (check_other_rows(field, piece, size, i))
			return(1);
	}

	// If the 1st row matches check the other rows of piece. If all rows match
	// save identity of piece on the board and return 1.
	// Else return 0 and go back to previous step.

	field[n]  = field[n] | piece[0];
	field[n + 1] = field[n + 1] | piece[1];
	bf_print(field, 8);
	return (0);
}


