/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_column.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:02:24 by esukava           #+#    #+#             */
/*   Updated: 2020/09/24 01:49:15 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t			bf_column(uint64_t *field, size_t col, size_t size)
{
	uint64_t		d;
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
