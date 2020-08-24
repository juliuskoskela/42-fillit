/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_column.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:02:24 by esukava           #+#    #+#             */
/*   Updated: 2020/08/24 15:03:37 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

uint			bf_column(uint *field, size_t row, size_t size)
{
	uint		d;
	size_t		i;

	i = 0;
	d = 0;
	while (i < size - 1)
	{
		if (checkbit(field[i], 0) == 1)
			d |= 1 << i;
		i++;
	}
	return (d);
}
