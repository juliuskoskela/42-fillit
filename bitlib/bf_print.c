/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:51:08 by esukava           #+#    #+#             */
/*   Updated: 2020/08/24 20:17:47 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

void			bf_print(uint64_t *field, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		printbits(field[i], size);
		write(1, "\n", 1);
		i++;
	}
}
