/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:46:04 by esukava           #+#    #+#             */
/*   Updated: 2020/08/24 20:17:18 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

uint64_t			*bf_init(size_t size)
{
	size_t		i;
	uint64_t		*field;

	i = 0;
	field = (uint64_t *)malloc(sizeof(uint64_t) * size);
	while (i < size - 1)
		field[i++] = 0;
	return (field);
}
