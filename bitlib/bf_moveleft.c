/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_moveleft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:03:50 by esukava           #+#    #+#             */
/*   Updated: 2020/08/24 15:05:36 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

void			bf_moveleft(uint *field, size_t steps, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size - 1)
	{
		field[i] = field[i] >> steps;
		i++;
	}
}
