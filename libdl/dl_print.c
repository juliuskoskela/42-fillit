/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:03:52 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/28 15:13:03 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdl.h"

void		dl_print(t_dlist *node)
{
	t_dlist	*last;

	while (node != NULL)
	{
		bf_print(node->content->row, node->content->w, node->content->h);
		last = node;
		node = node->next;
	}
}
