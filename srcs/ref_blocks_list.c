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

t_dlist		*ref_blocks_list(size_t j)
{
	t_dlist		*ref_blocks;
	t_field		*field;
	uint64_t	*i;
	ref_blocks = NULL;
	i = (uint64_t *)malloc(sizeof(uint64_t) * 19);

	i[0] = 0b0001000100010001;
	i[1] = 0b0000000000001111;
	i[2] = 0b0000000000110011;
	i[3] = 0b0000000000100111;
	i[4] = 0b0000001000110010;
	i[5] = 0b0000000001110010;
	i[6] = 0b0000000100110001;
	i[7] = 0b0000001100100010;
	i[8] = 0b0000000001000111;
	i[9] = 0b0000000001110001;
	i[10] = 0b0000000100010011;
	i[11] = 0b0000001100010001;
	i[12] = 0b0000000000010111;
	i[13] = 0b0000001000100011;
	i[14] = 0b0000000001110100;
	i[15] = 0b0000000001100011;
	i[16] = 0b0000000100110010;
	i[17] = 0b0000000000110110;
	i[18] = 0b0000001000110001;

	while (j < 19)
	{
		field = bf_new(4, 4);
		itofield(i[j], field);
		dl_putlast(&ref_blocks, field);
		j++;
	}
	free(i);
	return(ref_blocks);
}