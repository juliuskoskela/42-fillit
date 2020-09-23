/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:51:08 by esukava           #+#    #+#             */
/*   Updated: 2020/09/24 01:50:37 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			bf_print1(uint64_t *field, size_t w, size_t h)
{
	size_t		i;

	i = 0;
	while (i < h)
	{
		printbits(field[i], w);
		write(1, "\n", 1);
		i++;
	}
}

void			bf_print(t_field *field)
{
	if (!field)
		return ;
	bf_print1(field->row, field->w, field->h);
}
