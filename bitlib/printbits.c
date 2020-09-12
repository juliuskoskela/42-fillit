/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:44:16 by esukava           #+#    #+#             */
/*   Updated: 2020/09/12 01:32:13 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"
#include "stdio.h"

void			printbits(uint64_t nb, size_t size)
{
	size_t		i;
	char		c;

	i = 0;
	while (i < size)
	{
		c = checkbit(nb, i) ? '1' : '0';
		if (c == '1')
			printf("\e[1;35m%c\e[0m", c);
		else if (c == '0')
			printf("\e[1;36m%c\e[0m", c);
		//write(1, &c, 1);
		i++;
	}
}
