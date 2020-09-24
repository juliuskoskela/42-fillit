/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_del_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 05:24:38 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/24 14:54:01 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		dl_del_list(t_dlist **ref)
{
	t_field		*del;
	t_dlist		*pos;

	while (*ref)
	{
		pos = (*ref)->next;
		del = (*ref)->content;
		bf_del(del);
		free(*ref);
		*ref = pos;
	}
}