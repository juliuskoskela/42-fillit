/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:03:52 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/29 00:26:34 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdl.h"

void		dl_print(t_dlist *node)
{
	t_dlist	*last;
	t_field	*tmp;

	while (node != NULL)
	{
		tmp = node->content;
		bf_print(tmp->row, tmp->w, tmp->h);
		last = node;
		node = node->next;
	}
}