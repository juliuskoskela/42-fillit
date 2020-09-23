/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_fieldsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:29:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/24 01:53:33 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bf_fieldsize(t_field *field)
{
	size_t		x;
	size_t		y;
	size_t		i;
	size_t		nb;

	i = 0;
	y = 0;
	x = 0;
	if (!field)
		return ;
	while (i < field->h)
	{
		if (field->row[i] != 0)
		{
			y++;
			nb = ft_log2_64(field->row[i]) + 1;
			if (nb > x)
				x = nb;
		}
		i++;
	}
	field->h = y;
	field->w = x;
	field->bh = y;
	field->bw = x;
}
