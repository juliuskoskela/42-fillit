/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:46:04 by esukava           #+#    #+#             */
/*   Updated: 2020/08/24 16:45:32 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

unsigned int			*bf_init(size_t size)
{
	size_t		i;
	unsigned int		*field;

	i = 0;
	field = (unsigned int *)malloc(sizeof(unsigned int) * size);
	while (i < size - 1)
		field[i++] = 0;
	return (field);
}
