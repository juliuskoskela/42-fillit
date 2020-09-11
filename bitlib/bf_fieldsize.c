/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_fieldsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:29:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/11 02:31:27 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"
#include <math.h>

static int		ft_log2_64(uint64_t value)
{
	static uint64_t x = 0x07EDD5E59A4E28C2;
	static int tab64[64] = {
	63, 0, 58, 1, 59, 47, 53, 2,
	60, 39, 48, 27, 54, 33, 42, 3,
	61, 51, 37, 40, 49, 18, 28, 20,
	55, 30, 34, 11, 43, 14, 22, 4,
	62, 57, 46, 52, 38, 26, 32, 41,
	50, 36, 17, 19, 29, 10, 13, 21,
	56, 45, 25, 31, 35, 16, 9, 12,
	44, 24, 15, 8, 23, 7, 6, 5};

	value |= value >> 1;
	value |= value >> 2;
	value |= value >> 4;
	value |= value >> 8;
	value |= value >> 16;
	value |= value >> 32;
	return (tab64[((uint64_t)((value - (value >> 1)) * x)) >> 58]);
}

void	bf_fieldsize(t_field *field)
{
	size_t		x;
	size_t		y;
	size_t		i;
	size_t		nb;

	i = 0;
	y = 0;
	x = 0;
	while (i < field->h)
	{
		if (field->row[i] != 0)
		{
			y++;
			nb = ft_log2_64(field->row[i]) + 1;
			if (nb > x)
				x = nb;
		}
		i++;
	}
	field->h = y;
	field->w = x;
}
