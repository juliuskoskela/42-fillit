/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:44:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/27 15:29:16 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib/bitlib.h"
#include "libft/libft.h"

typedef struct		s_field
{
	uint64_t		*row;
	int				w;
	int				h;
}					t_field;

t_field			bf_copy(t_field source)
{
	t_field		dest;
	int			i;

	i = 0;
	dest.row = bf_init(source.h);
	dest.h = source.h;
	dest.w = source.w;
	while (i < source.h)
	{
		dest.row[i] = source.row[i];
		i++;
	}
	return (dest);
}

int		checkrows(t_field *field, t_field *blocks, int i, int j, int n)
{
	if ((blocks->row[0] & field->row[n]) != 0)
	{
		if (j == field->w - blocks->w)
			return(0);
		blocks->row[0] = blocks->row[0] << 1;
		checkrows(field, blocks, i, j + 1, n);
	}
	while (i < blocks->h - 1)
	{
		field->row[n] = field->row[n] | blocks->row[0];
		blocks->row[i] = blocks->row[i] << j;
		if ((blocks->row[i] & field->row[n + i]) != 0)
			checkrows(field, blocks, 1, j, n);
		else
		{
			field->row[n + i] = field->row[n + i] | blocks->row[i];
			i++;
		}
	}
	return (1);
}

int				solver_d1(t_field *field, t_field **blocks, int i, int n, int blocks_count)
{
	int			r;
	t_field 	tmp;

	r = 0;
	tmp = bf_copy(*blocks[i]);
	if (n < field->h - blocks[0][i].h - 1)
	{
		r = checkrows(field, &blocks[0][i], 0, 0, n);
		if (r == 0 && i == blocks_count - 1)
			return (0);
		if (r == 1 && i < blocks_count - 1)
			solver_d1(field, blocks, i + 1, 0, blocks_count);
		else
		{
			blocks[i] = &tmp;
			solver_d1(field, blocks, i, n + 1, blocks_count);
		}
	}
	return (1);
}

int		solver(t_field *field, t_field **blocks, int blocks_count)
{
	int			r;

	field->row = bf_init(field->w);
	r = solver_d1(field, blocks, 0, 0, blocks_count);
	if (r == 0)
	{
		free(field->row);
		field->w++;
		field->h++;
		solver(field, blocks, blocks_count);
	}
	return (1);
}

int			main(void)
{
	int		blocks_count = 3;
	t_field		**blocks;

				blocks = (t_field **)malloc(sizeof(t_field));
				*blocks = (t_field *)malloc(sizeof(t_field) * blocks_count);

				blocks[0]->row = (uint64_t *)malloc(sizeof(uint64_t) * 4);
					blocks[0]->row[0] = b("011");
					blocks[0]->row[1] = b("110");
					blocks[0]->h = 2;
					blocks[0]->w = 3;
				blocks[1]->row = (uint64_t *)malloc(sizeof(uint64_t) * 5);
					blocks[1]->row[0] = b("11");
					blocks[1]->row[1] = b("01");
					blocks[1]->row[2] = b("01");
					blocks[1]->h = 3;
					blocks[1]->w = 2;
				blocks[2]->row = (uint64_t *)malloc(sizeof(uint64_t) * 6);
					blocks[2]->row[0] = b("1");
					blocks[2]->row[1] = b("1");
					blocks[2]->row[2] = b("1");
					blocks[2]->row[3] = b("1");
					blocks[2]->h = 4;
					blocks[2]->w = 1;

	t_field		field;

				field.row = bf_init(4);
				field.w = 4;
				field.h = 4;

	solver(&field, blocks, blocks_count);
	bf_print(field.row, field.w);
	return (0);
}
