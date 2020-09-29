/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref_blocks_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 02:36:45 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/30 02:36:50 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_field		*itofield(uint64_t nb, t_field *field)
{
	field->row[0] = nb & 0b1111;
	field->row[1] = (nb >> 4) & 0b1111;
	field->row[2] = (nb >> 8) & 0b1111;
	field->row[3] = (nb >> 12) & 0b1111;
	return (field);
}

t_dlist		*ref_blocks_list()
{
	t_dlist		*ref_blocks;
	t_field		*field;

	ref_blocks = NULL;

	uint64_t	*i;
	size_t		j = 0;

	i = (uint64_t *)malloc(sizeof(uint64_t));

	i[0] = 0b1000100010001000;
	i[1] = 0b1111000000000000;
	i[2] = 0b1100110000000000;
	i[3] = 0b1110010000000000;
	i[4] = 0b0100110001000000;
	i[5] = 0b0100111000000000;
	i[6] = 0b1000110010000000;
	i[7] = 0b0100010011000000;
	i[8] = 0b1110001000000000;
	i[9] = 0b1000111000000000;
	i[10] = 0b1100100010000000;
	i[11] = 0b1000100011000000;
	i[12] = 0b1110100000000000;
	i[13] = 0b1100010001000000;
	i[14] = 0b0010111000000000;
	i[15] = 0b1100011000000000;
	i[16] = 0b0100110010000000;
	i[17] = 0b0110110000000000;
	i[18] = 0b1000110001000000;

	while (j < 19)
	{
		field = bf_new(4, 4);
		itofield(i[j], field);
		dl_putlast(&ref_blocks, field);
		j++;
	}
	return(ref_blocks);
}