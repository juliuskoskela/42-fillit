/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_column.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:02:24 by esukava           #+#    #+#             */
/*   Updated: 2020/08/24 16:51:45 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

unsigned int			bf_column(unsigned int *field, size_t col, size_t size)
{
	unsigned int		d;
	size_t		i;

	i = 0;
	d = 0;
	while (i < size - 1)
	{
		if (checkbit(field[i], col) == 1)
			d |= 1 << i;
		i++;
	}
	return (d);
}
