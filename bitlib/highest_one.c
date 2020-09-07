/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highest_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:13:55 by esukava           #+#    #+#             */
/*   Updated: 2020/09/07 14:18:04 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

size_t			highest_one(uint64_t nb, size_t size)
{
	size_t		i;

	i = size - 1;
	while (i > 0)
	{
		if (((nb >> i) & 1) == 1)
			return(i + 1);
		i--;
	}
	return(0);
}
