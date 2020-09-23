/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:46:04 by esukava           #+#    #+#             */
/*   Updated: 2020/09/24 01:49:47 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t			*bf_init(size_t size)
{
	size_t		i;
	uint64_t	*field;

	i = 0;
	field = (uint64_t *)malloc(sizeof(uint64_t) * size);
	while (i < size)
	{
		field[i] = 0;
		i++;
	}
	return (field);
}
