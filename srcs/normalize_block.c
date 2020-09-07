/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_block.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:15:47 by esukava           #+#    #+#             */
/*   Updated: 2020/09/04 19:49:20 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		check_columns(t_field *tmp)
{
	uint64_t	x;
	size_t		i;

	x = 0;
	i = 0;
	while (tmp->row[0] == 0 && i++ <= 4)
	{
		x = tmp->row[0];
		tmp->row[0] = tmp->row[1];
		tmp->row[1] = tmp->row[2];
		tmp->row[2] = tmp->row[3];
		tmp->row[3] = x;
	}
	return ;
}

static int		check_rows(uint64_t *row)
{
	if ((((row[0] >> 0) & 1) == 1) ||
		(((row[1] >> 0) & 1) == 1) ||
		(((row[2] >> 0) & 1) == 1) ||
		(((row[3] >> 0) & 1) == 1))
		return (1);
	return (0);
}

void			normalize_block(t_field *input)
{
	uint64_t	x;
	size_t		i;

	i = 0;
	check_columns(input);
	while (check_rows(input->row) == 0 && i <= 4)
	{
		x = 0;
		while (x != 4)
		{
			input->row[x] = input->row[x] >> 1;
			x++;
		}
		i++;
	}
}
