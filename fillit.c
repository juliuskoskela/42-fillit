/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:44:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/26 16:14:04 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib/bitlib.h"
#include "libft/libft.h"

typedef struct		s_tetriminoe
{
	uint64_t		*row;
	size_t			w;
	size_t			h;
}					t_tet;

typedef struct		s_field
{
	uint64_t		*row;
	size_t			size;
}					t_field;

uint64_t		check_rest(t_field *field, t_tet *piece, size_t i)
{
	size_t		j;

	j = 1;
	while (j > piece->h)
	{
		piece->row[0] == piece->row[0] << i;
	}
}
int		solver(t_field *field, t_tet *piece, size_t i)
{
	size_t	n = 0;
	int		r = 0;
	uint64_t tmp = piece->row[0];

	// Check piece 1st row against corresponding row of field.
	if (tmp & field->row[n] != 0 && i <= field->size - piece->w)
	{
		tmp = tmp << 1;
		solver(field, piece, i + 1);
	}
	else
	{
		if (check_rest(field, piece, i))
		{
			field->row[n]  = field->row[n] | piece->row[0];
			field->row[n + 1] = field->row[n + 1] | piece->row[1];
			return(1);
		}
	}
	// If the 1st row matches check the other rows of piece. If all rows match
	// save identity of piece on the board and return 1.
	// Else return 0 and go back to previous step.
	return (0);
}

int			main(void)
{
	size_t		n = 0;
	size_t		i = 0;
	t_field		field;

				field.row = bf_init(8);
				field.row[0] = b("11111110");
				field.row[1] = b("10000000");
				field.row[2] = b("00000000");
				field.row[3] = b("00000000");
				field.row[4] = b("00000000");
				field.row[5] = b("00000000");
				field.row[6] = b("00000000");
				field.row[7] = b("00000000");

				field.size = 8;

	t_tet		block1;

				block1.row = (int *)malloc(sizeof(int) * 2);
				block1.row[0] = b("011");
				block1.row[1] = b("110");

				block1.w = 3;
				block1.h = 2;

	solver(&field, &block1, 0);
	//bf_print(field, 8);
	return (0);
}
