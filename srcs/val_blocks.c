/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_blocks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:21:20 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/29 18:47:57 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				val_blocks(t_dlist *input, t_dlist *ref)
{
	t_dlist		*pos;
	t_field		*f1;
	t_field		*f2;
	int			r;

	pos = ref;
	while (input)
	{
		f1 = input->content;
		input = input->next;
		while (pos)
		{
			f2 = pos->content;
			pos = pos->next;
			r = bf_cmp(f1, f2);
			if (r == 1)
				break ;
		}
		if (r == 0)
			return (0);
		pos = ref;
	}
	return (1);
}
