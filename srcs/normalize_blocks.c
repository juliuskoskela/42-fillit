/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_blocks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:15:47 by esukava           #+#    #+#             */
/*   Updated: 2020/09/04 15:58:44 by jkoskela         ###   ########.fr       */
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

void			normalize_blocks(t_dlist *input)
{
	t_field		*tmp;
	uint64_t	x;
	size_t		i;

	while (input != NULL)
	{
		i = 0;
		tmp = input->content;
		check_columns(tmp);
		while (check_rows(tmp->row) == 0 && i <= 4)
		{
			x = 0;
			while (x != 4)
			{
				tmp->row[x] = tmp->row[x] >> 1;
				x++;
			}
			i++;
		}
		input = input->next;
	}
}
