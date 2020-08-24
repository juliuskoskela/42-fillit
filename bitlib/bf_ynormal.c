/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_ynormal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:59:36 by esukava           #+#    #+#             */
/*   Updated: 2020/08/24 16:46:58 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

void			bf_ynormal(unsigned int *field, size_t size)
{
	size_t		i;

	i = 0;
	while (field[0] == 0)
	{
		while (i < size - 1)
		{
			field[i] = field[i  + 1];
			i++;
		}
		i = 0;
	}
	field[size - 1] = 0;
}
