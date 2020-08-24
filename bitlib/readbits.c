/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readbits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:42:11 by esukava           #+#    #+#             */
/*   Updated: 2020/08/24 14:42:42 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

uint			readbits(char *str, char c, int size)
{
	size_t		i;
	uint		nb;

	i = 0;
	nb = 0;
	while (i < size)
	{
		if (str[i] == c)
			nb |= 1 << i;
		if (str[i] != '\n')
			i++;
	}
	return (nb);
}
