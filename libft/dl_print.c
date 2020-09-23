/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:03:52 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/24 01:51:22 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		dl_print(t_dlist *node)
{
	t_dlist	*last;
	t_field	*tmp;

	while (node != NULL)
	{
		tmp = node->content;
		bf_print(tmp);
		last = node;
		node = node->next;
	}
}
