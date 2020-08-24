/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowest_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:15:02 by esukava           #+#    #+#             */
/*   Updated: 2020/08/24 16:56:18 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

int				lowest_one(unsigned int nb, size_t size)
{
	size_t		i;

	i = 0;
	while (i <= (size - 1))
	{
		if (((nb >> i) & 1) == 1)
			return (i);
		i++;
	}
	return (0);
}
