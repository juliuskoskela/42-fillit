/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:44:16 by esukava           #+#    #+#             */
/*   Updated: 2020/08/24 23:38:29 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

void			printbits(uint64_t nb, size_t size)
{
	size_t		i;
	char		c;

	i = 0;
	while (i < size)
	{
		c = checkbit(nb, i) ? '1' : '0';
		write(1, &c, 1);
		i++;
	}
}
