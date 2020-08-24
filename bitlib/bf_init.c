/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:46:04 by esukava           #+#    #+#             */
/*   Updated: 2020/08/24 14:49:41 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

uint			*bf_init(size_t size)
{
	size_t		i;
	uint		*field;

	i = 0;
	field = (uint *)malloc(sizeof(uint) * size);
	while (i < size - 1)
		field[i++] = 0;
	return (field);
}
