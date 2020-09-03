/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalblocks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 18:15:47 by esukava           #+#    #+#             */
/*   Updated: 2020/09/03 17:45:00 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../bitlib/bitlib.h"
#include "../libdl/libdl.h"

static void	setuppies(t_field *tmp)
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

static int	checklefties(uint64_t *row)
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
	size_t		i;

	while (input != NULL)
	{
		i = 0;
		tmp = input->content;
		setuppies(tmp);
		while (checklefties(tmp->row) == 0 && i <= 4)
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
