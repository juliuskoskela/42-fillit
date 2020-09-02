/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalblocks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:15:47 by esukava           #+#    #+#             */
/*   Updated: 2020/09/02 19:04:46 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../bitlib/bitlib.h"
#include "../libdl/libdl.h"

int			checklefties(uint64_t *row)
{
	if ((((row[0] >> 0) & 1) == 1) ||
		(((row[1] >> 0) & 1) == 1) ||
		(((row[2] >> 0) & 1) == 1) ||
		(((row[3] >> 0) & 1) == 1))
		return (1);
	return (0);
}

void		normalblocks(t_dlist *input)
{
	t_field		*tmp;
	uint64_t	x;

	while (input != NULL)
	{
		tmp = input->content;
		while (tmp->row[0] == 0)
		{
			x = tmp->row[0];
			tmp->row[0] = tmp->row[1];
			tmp->row[1] = tmp->row[2];
			tmp->row[2] = tmp->row[3];
			tmp->row[3] = x;
		}
		while (checklefties(tmp->row) == 0)
		{
			x = 0;
			while (x != 4)
			{
				tmp->row[x] = tmp->row[x] >> 1;
				x++;
			}
		}
		input = input->next;
	}
}
