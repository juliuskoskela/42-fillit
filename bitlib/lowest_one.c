/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowest_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:15:02 by esukava           #+#    #+#             */
/*   Updated: 2020/08/24 20:29:39 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

size_t			lowest_one(uint64_t nb, size_t size)
{
	size_t		i;

	i = 0;
	while (i <= size - 1)
	{
		if (((nb >> i) & 1) == 1)
			return (i);
		i++;
	}
	return (0);
}
