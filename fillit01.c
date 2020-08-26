/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:44:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/26 21:34:03 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib/bitlib.h"
#include "libft/libft.h"

typedef struct		s_field
{
	uint64_t		*row;
	int			w;
	int			h;
}					t_field;

int		checkrows(t_field *field, t_field *block, int i, int j, int n)
{
	if (j == field->w - block->w)
		return(0);
	if ((block->row[0] & field->row[n]) != 0)
	{
		block->row[0] = block->row[0] << 1;
		checkrows(field, block, i, j + 1, n);
	}
	if (i < block->h)
	{
		field->row[n] = field->row[n] | block->row[0];
		block->row[i] = block->row[i] << j;
		if ((block->row[i] & field->row[n + i]) != 0)
			checkrows(field, block, 1, j, n);
		else
		{
			field->row[n + i] = field->row[n + i] | block->row[i];
			checkrows(field, block, i + 1, j, n);
		}
	}
	return (1);
}

int		solver_d1(t_field *field, t_field **block, int i, int n, int block_count)
{
	int		r;

	r = 0;
	if (n < field->h - block[0][i].h - 1)
	{
		r = checkrows(field, &block[0][i], 0, 0, n);
		if (r == 1)
			solver_d1(field, block, i + 1, 0, block_count);
		else
			solver_d1(field, block, i, n + 1, block_count);
	}
	if (r == 0 && i == block_count)
		return (0);
	return (1);
}

int		solver(t_field *field, t_field **block, int block_count)
{
	int			r;

	field->row = bf_init(field->w);
	r = solver_d1(field, block, 0, 0, block_count);
	if (r == 0)
	{
		free(field->row);
		field->w++;
		field->h++;
		solver(field, block, block_count);
	}
	return (1);
}

int			main(void)
{
	int		block_count = 3;
	t_field		*blocks;

				blocks = (t_field *)malloc(sizeof(t_field) * block_count);

				blocks[0].row = (uint64_t *)malloc(sizeof(uint64_t) * 4);
					blocks[0].row[0] = b("011");
					blocks[0].row[1] = b("110");
					blocks[0].h = 2;
					blocks[0].w = 3;
				blocks[1].row = (uint64_t *)malloc(sizeof(uint64_t) * 5);
					blocks[1].row[0] = b("11");
					blocks[1].row[1] = b("10");
					blocks[1].row[2] = b("10");
					blocks[1].h = 3;
					blocks[1].w = 2;
				blocks[2].row = (uint64_t *)malloc(sizeof(uint64_t) * 6);
					blocks[2].row[0] = b("1");
					blocks[2].row[1] = b("1");
					blocks[2].row[2] = b("1");
					blocks[2].row[3] = b("1");
					blocks[2].h = 4;
					blocks[2].w = 1;

	t_field		field;

				field.row = bf_init(1);
				field.w = 4;
				field.h = 4;

	solver(&field, &blocks, block_count);
	bf_print(field.row, field.w);
	return (0);
}
